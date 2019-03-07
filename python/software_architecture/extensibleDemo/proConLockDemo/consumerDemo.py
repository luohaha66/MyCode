import threading
import queue
import urllib.request
import uuid
import datetime
from PIL import Image

from software_architecture.extensibleDemo.proConLockDemo.producerDemo import ThumbnailGenerates, ThumbnailProducer


class ThumbnailSaverTop(object):
    """
    class which saves urls to thumbnail images and keeps a counter
    """

    def __init__(self, limit=20, low=None):
        self._limit = limit
        self._lock = threading.Lock()
        self._counter = {}
        self._low_half = low

    def _thumbnail(self, url: str, size=(64, 64), format='.png'):
        """save thumbnail for an image URL"""
        img = Image.open(urllib.request.urlopen(url))

        # get filename
        pieces = url.split('/')
        filename = '{}_{}{}'.format(pieces[-2], pieces[-1].split('.')[0], format)
        img.thumbnail(size, Image.ANTIALIAS)
        img.save(filename)
        self._counter[filename] = 1
        print('Saved', filename)

    def save(self, url):
        with self._lock:
            if len(self._counter) >= self._limit:
                return False
            if self._low_half:
                self._low_half.put(url)
                self._counter[url] = 1
                return True
            else:
                self._counter[url] = 1
                self._thumbnail(url)
                return True

    def save_up_to_limit(self):
        with self._lock:
            if len(self._counter) >= self._limit:
                return True
            return False


class ThumbnailSaverLow(threading.Thread):
    def __init__(self, low: queue.Queue):
        super().__init__()
        self._low_half = low
        self._time_out = 1
        self._id = uuid.uuid4().hex

    def __str__(self):
        return 'Saver_low_half: ' + self._id

    def _thumbnail(self, url: str, size=(64, 64), format='.png'):
        """save thumbnail for an image URL"""
        img = Image.open(urllib.request.urlopen(url))

        # get filename
        pieces = url.split('/')
        filename = '{}_{}{}'.format(pieces[-2], pieces[-1].split('.')[0], format)
        img.thumbnail(size, Image.ANTIALIAS)
        img.save(filename)
        print(self, 'Saved', filename)

    def run(self):
        while True:
            try:
                self._thumbnail(self._low_half.get(timeout=self._time_out))
            except queue.Empty:
                break


class ThumbnailConsumer(threading.Thread):
    """
    worker class that consumer image urls and generate thumbnails
    """
    def __init__(self, tsk_queue: queue.Queue, saver, time_out=1):
        super().__init__()
        self._tsk_queue = tsk_queue
        self._time_out = time_out
        self._running = True
        self._saver = saver
        self._id = uuid.uuid4().hex

    def __str__(self):
        return 'Consumer: ' + self._id

    def run(self):
        while self._running:
            try:
                url = self._tsk_queue.get(timeout=self._time_out)
                print(self, 'Get', url)
                if not self._saver.save(url):
                    break
            except queue.Empty:
                if self._saver.save_up_to_limit():
                    break


# cost time 0:00:52.247270
def run_without_top_half():
    a = datetime.datetime.now()

    tsk_queue = queue.Queue(maxsize=25)
    generates = ThumbnailGenerates()
    saver = ThumbnailSaverTop()
    pro, con = [], []
    for i in range(3):
        t = ThumbnailProducer(tsk_queue, generates)
        pro.append(t)
        t.start()

    for i in range(5):
        t = ThumbnailConsumer(tsk_queue, saver)
        con.append(t)
        t.start()

    for t in con:
        t.join()

    print('all producer stopped, cost time', datetime.datetime.now() - a)


# cost time 0:00:10.487973
def run_with_top_half():
    # fixme we can't ensure that all task exec success
    a = datetime.datetime.now()

    tsk_queue = queue.Queue(maxsize=25)
    low_queue = queue.Queue(maxsize=25)

    generates = ThumbnailGenerates()
    saver = ThumbnailSaverTop(low=low_queue)
    pro, con, low = [], [], []
    for i in range(3):
        t = ThumbnailProducer(tsk_queue, generates)
        pro.append(t)
        t.start()

    for i in range(5):
        t = ThumbnailConsumer(tsk_queue, saver)
        con.append(t)
        t.start()

    for i in range(5):
        t = ThumbnailSaverLow(low_queue)
        low.append(t)
        t.start()

    for t in low:
        t.join()

    print('all producer stopped, cost time', datetime.datetime.now() - a)


if __name__ == '__main__':
    run_with_top_half()
