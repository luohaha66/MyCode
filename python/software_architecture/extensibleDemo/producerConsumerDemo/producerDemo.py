import threading
import string
import random
import queue
import time


class ThumbnailProducer(threading.Thread):
    """
    work class that generates image urls
    """

    def __init__(self, tsk_queue: queue.Queue, time_out=1):
        super().__init__()
        self.tsk_queue = tsk_queue
        self.time_out = time_out
        self._running = True

        # choices of size
        self._sizes = [240, 320, 360, 480]
        self._url_template = 'https://dummyimage.com/%s/%s/%s.jpg'

    def __str__(self):
        return 'Consumer'

    def _get_size(self):
        return '%d' % random.choice(self._sizes)

    def _get_color(self):
        return ''.join(random.sample(string.hexdigits[:-6], 3))

    def run(self):
        while self._running:
            url = self._url_template % (self._get_size(),
                                        self._get_color(),
                                        self._get_color())
            try:
                self.tsk_queue.put(url)
            except queue.Full:
                pass
            print(self, 'Put ', url)
            time.sleep(1)

    def stop(self):
        self._running = False


if __name__ == '__main__':
    print(''.join(random.sample(string.hexdigits[:-6], 3)))
