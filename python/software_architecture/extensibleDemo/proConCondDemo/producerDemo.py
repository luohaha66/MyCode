import threading
import string
import random
import queue
import time
import uuid


class ThumbnailControl(threading.Thread):
    """
    a rate limit controller thread for urls using condition
    """
    def __init__(self, rate, p_threads):
        super().__init__()
        self._rate = rate
        self._rate_h = self._rate * 1.05
        self._rate_l = self._rate * 0.95
        self._p_threads = p_threads
        self._start_t = time.time()
        self._running = True
        self._cond = threading.Condition()
        self.url_counts = 0

    def _calc_rate(self):
        # fixme we don't to protect this var use a thread lock
        return 60.0 * self.url_counts / (time.time() - self._start_t)

    def increment(self):
        # fixme we don't to protect this var use a thread lock
        self.url_counts += 1

    def run(self):
        while self._running:
            if self._calc_rate() <= self._rate:
                with self._cond:
                    # wake up all producer threads to generate url
                    self._cond.notify_all()

    def stop(self):
        self._running = False

    def throttle(self, p_thread):
        """
        the method throttle to manage rate
        """
        # get current rate
        current_rate = self._calc_rate()
        print('Current rate: ', current_rate)

        # if current_rate > limit, add more sleep time to thread
        sleep_diff = abs(current_rate - self._rate) / (self._p_threads * 60.0)

        if current_rate > self._rate_h:
            # add sleep time for each thread
            p_thread.sleep_time += sleep_diff
            # block this thread
            with self._cond:
                print('Controller, rate is high, sleep more', current_rate, sleep_diff)
                self._cond.wait()
        if current_rate < self._rate_l:
            print('Controller, rate is low, sleep less', current_rate, sleep_diff)
            sleep_time = p_thread.sleep_time
            sleep_time -= sleep_diff
            p_thread.sleep_time = max(0, sleep_time)


class ThumbnailProducer(threading.Thread):
    """
    work class that generates image urls
    """

    def __init__(self, tsk_queue: queue.Queue, control: ThumbnailControl, sleep_time=1, time_out=1):
        super().__init__()
        self._tsk_queue = tsk_queue
        self._time_out = time_out
        self._control = control
        self._running = True
        self._id = uuid.uuid4().hex

        # choices of size
        self._sizes = [240, 320, 360, 480]
        self._url_template = 'https://dummyimage.com/%s/%s/%s.jpg'

        self.sleep_time = sleep_time

    def __str__(self):
        return 'Producer: ' + self._id

    def _get_size(self):
        return '%d' % random.choice(self._sizes)

    def _get_color(self):
        return ''.join(random.sample(string.hexdigits[:-6], 3))

    def _generate_url(self):
        return self._url_template % (self._get_size(),
                                     self._get_color(),
                                     self._get_color())

    def stop(self):
        self._running = False

    def run(self):
        while self._running:
            try:
                url = self._generate_url()
                self._tsk_queue.put(url, timeout=self._time_out)
                print(self, 'Put ', url)

                self._control.increment()
                # throttle after putting a few images
                if self._control.url_counts > 5:
                    self._control.throttle(self)
                time.sleep(self.sleep_time)
            except queue.Full:
                break


if __name__ == '__main__':
    tsk_queue = queue.Queue(maxsize=100)

    control = ThumbnailControl(rate=360, p_threads=3)

    pro = []
    for i in range(3):
        t = ThumbnailProducer(tsk_queue, control)
        pro.append(t)
        t.start()

    control.start()

    for t in pro:
        t.join()

    control.stop()

    print('all task finished')
