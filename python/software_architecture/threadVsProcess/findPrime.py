import threading
import queue
import datetime
import multiprocessing


def is_prime(n):
    """
    check for input number prime
    """
    v_root = int(n ** 0.5) + 1
    for i in range(3, v_root, 2):
        if n % i == 0:
            return False
    print(n, 'is prime')
    return True


class PrimerChecker(threading.Thread):
    def __init__(self, n_queue: queue.Queue):
        super().__init__()
        self._n_queue = n_queue

    def run(self):
        while True:
            try:
                is_prime(self._n_queue.get(timeout=1))
            except queue.Empty:
                break


# cost time 0:00:32.200750
# because GIL, the global interpreter lock, the thread can't use all cpu kernel
def thread_run(number_list: list):
    a = datetime.datetime.now()

    n_queue = queue.Queue(maxsize=1000)
    for each in number_list:
        n_queue.put(each)

    checker = []
    for i in range(2):
        t = PrimerChecker(n_queue)
        checker.append(t)
        t.start()

    for t in checker:
        t.join()

    print('all checker stopped, cost time', datetime.datetime.now() - a)


# cost time 0:00:20.221331, my machine just have two kernel
def process_run(number_list: list):
    a = datetime.datetime.now()
    pool = multiprocessing.Pool(2)
    pool.map(is_prime, number_list)
    print('all checker stopped, cost time', datetime.datetime.now() - a)


if __name__ == '__main__':
    number = [1297337, 1116281, 10439523, 472882027, 533000389, 817504243,
              982451653, 1122725355095293, 115280095190773, 10++726899285419] * 40
    # thread_run(number)
    process_run(number)
