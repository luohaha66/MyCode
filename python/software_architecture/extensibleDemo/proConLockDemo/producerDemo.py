import threading
import string
import random
import queue
# import time
import uuid


class ThumbnailGenerates(object):
    """
    class that generates image urls with a counter
    """
    def __init__(self, limit=25):
        self._limit = limit
        self._lock = threading.Lock()
        self._counter = {}

        # choices of size
        self._sizes = [240, 320, 360, 480]
        self._url_template = 'https://dummyimage.com/%s/%s/%s.jpg'

    def _get_size(self):
        return '%d' % random.choice(self._sizes)

    def _get_color(self):
        return ''.join(random.sample(string.hexdigits[:-6], 3))

    def generate_url(self):
        with self._lock:
            if len(self._counter) >= self._limit:
                return False
            url = self._url_template % (self._get_size(),
                                        self._get_color(),
                                        self._get_color())
            self._counter[url] = 1
            return url


class ThumbnailProducer(threading.Thread):
    """
    work class that generates image urls
    """

    def __init__(self, tsk_queue: queue.Queue, generate, time_out=1):
        super().__init__()
        self._tsk_queue = tsk_queue
        self._time_out = time_out
        self._generate = generate
        self._running = True
        self._id = uuid.uuid4().hex

    def __str__(self):
        return 'Producer: ' + self._id

    def run(self):
        while self._running:
            try:
                url = self._generate.generate_url()
                if not url:
                    break
                else:
                    self._tsk_queue.put(url, timeout=self._time_out)
                    print(self, 'Put ', url)
            except queue.Full:
                pass


if __name__ == '__main__':
    # print(''.join(random.sample(string.hexdigits[:-6], 3)))
    tsk_queue = queue.Queue(maxsize=25)
    generates = ThumbnailGenerates()
    pro = []
    for i in range(3):
        t = ThumbnailProducer(tsk_queue, generates)
        pro.append(t)
        t.start()

    for t in pro:
        t.join()
