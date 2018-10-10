from threading import Lock, Thread
import requests

# sometimes there might be situations where two or more threads are trying to write to
# the same resource at the same time or where the output is dependent on the
# sequence or timing of certain events. The way this can be avoided is by using a
# Lock that each thread needs to acquire before writing to a shared resource.
# Locks can be acquired and released through either the contextmanager
# protocol (with statement), or by using acquire() and release() directly
file_lock = Lock()


# When log() is called, it will wait to acquire the lock
# with with file_lock:. This ensures that at any one time, only one thread is writing to the file
def log(msg):
    interval = ['\n*********************\n'] * 5
    with file_lock:
        with open('website_changes.log', 'a') as f:
            f.write(msg)
            f.writelines(interval)


def monitor_website(some_website):
    """
    Monitor a website and then if there are any changes,
    log them to disk.
    """
    changes = requests.get(some_website)
    if changes:
        log(changes.text)


if __name__ == '__main__':
    websites = ['http://sogou.com/', 'http://baidu.com/', 'http://baidu.com/']
    for website in websites:
        t = Thread(target=monitor_website, args=(website,))
        t.start()
