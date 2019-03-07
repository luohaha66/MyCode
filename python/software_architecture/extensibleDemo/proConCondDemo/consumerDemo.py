import threading
import queue
import urllib.request
import uuid
import datetime
from PIL import Image

from software_architecture.extensibleDemo.proConCondDemo.producerDemo import ThumbnailProducer, ThumbnailControl


class ThumbnailSaver(object):
    """
    class which saves urls to thumbnail images and keeps a counter
    """

    def __init__(self, limit=20):
        self._limit = limit
        self._sem = threading.BoundedSemaphore(value=limit)

    def _acquire(self):
        # acquire sem, if limit is exhausted, return false
        return self._sem.acquire(blocking=False)

    def _release(self):
        # release sem, increment count
        return self._sem.release()

    def _thumbnail(self, url: str, size=(64, 64), format='.png'):
        """save thumbnail for an image URL"""
        img = Image.open(urllib.request.urlopen(url))

        # get filename
        pieces = url.split('/')
        filename = '{}_{}{}'.format(pieces[-2], pieces[-1].split('.')[0], format)
        try:
            img.thumbnail(size, Image.ANTIALIAS)
            img.save(filename)
            print('Saved', filename)
        except Image.DecompressionBombError:
            # if thumbnail save failed, we release the sem
            print('save thumbnail failed')
            self._release()

    def save(self, url):
        if self._acquire():
            self._thumbnail(url)
            return True
        else:
            print('Sem limit reached')
            return False

    def save_up_to_limit(self):
        print('queue is empty')
        return not self._acquire()


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


# cost time 0:00:16.788192
def run():
    a = datetime.datetime.now()

    tsk_queue = queue.Queue(maxsize=25)
    control = ThumbnailControl(rate=360, p_threads=3)
    saver = ThumbnailSaver()

    pro, con = [], []
    for i in range(3):
        t = ThumbnailProducer(tsk_queue, control)
        pro.append(t)
        t.start()

    control.start()

    for i in range(5):
        t = ThumbnailConsumer(tsk_queue, saver)
        con.append(t)
        t.start()

    for t in con:
        t.join()

    # for t in pro:
    #     t.stop()

    control.stop()

    print('all producer stopped, cost time', datetime.datetime.now() - a)


if __name__ == '__main__':
    run()
