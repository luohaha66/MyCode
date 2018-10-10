from threading import Thread
import requests


def get_web_page(url):
    page = requests.get(url)
    return page


if __name__ == '__main__':
    # class threading.Thread(group=None, target=None, name=None, args=(), kwargs={}, *, daemon=None)
    some_thread = Thread(target=get_web_page, args=('http://baidu.com/',))
    some_thread.start()
    # To wait until the thread has terminated
    some_thread.join()
    # After calling join(), it is always a good idea to check
    # whether the thread is still alive (because the join call timed out):
    if some_thread.is_alive():
        print("join() must have timed out.")
    else:
        print("Our thread has terminated.")