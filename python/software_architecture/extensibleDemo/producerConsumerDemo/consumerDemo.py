import threading
import queue
import urllib.request
import time
from PIL import Image

from software_architecture.extensibleDemo.producerConsumerDemo.producerDemo import ThumbnailProducer


class ThumbnailConsumer(threading.Thread):
    """
    worker class that consumer image urls and generate thumbnails
    """
    SAVED = 0

    def __init__(self, tsk_queue: queue.Queue, time_out=1):
        super().__init__()
        self.tsk_queue = tsk_queue
        self.time_out = time_out
        self._running = True

    def __str__(self):
        return 'Consumer'

    def _thumbnail(self, url: str, size=(64, 64), format='.png'):
        """save thumbnail for an image URL"""
        img = Image.open(urllib.request.urlopen(url))

        # get filename
        pieces = url.split('/')
        filename = '{}_{}{}'.format(pieces[-2], pieces[-1].split('.')[0], format)
        img.thumbnail(size, Image.ANTIALIAS)
        img.save(filename)
        ThumbnailConsumer.SAVED += 1
        print(self, 'Saved', filename)

    def run(self):
        while self._running:
            try:
                self._thumbnail(self.tsk_queue.get(timeout=self.time_out))
            except queue.Empty:
                pass

    def stop(self):
        self._running = False


if __name__ == '__main__':
    tsk_queue = queue.Queue(maxsize=15)
    pro, con = [], []
    for i in range(2):
        t = ThumbnailProducer(tsk_queue)
        pro.append(t)
        t.start()

    for i in range(3):
        t = ThumbnailConsumer(tsk_queue)
        con.append(t)
        t.start()

    time.sleep(15)
    if ThumbnailConsumer.SAVED > 10:
        for each in pro:
            each.stop()
        for each in con:
            each.stop()

    print('all tsk finished')
