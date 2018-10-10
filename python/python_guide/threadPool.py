from concurrent.futures import ThreadPoolExecutor
import requests


def get_web_page(url):
    pages = requests.get(url)
    return pages


def finished(future):
    print(future.done())
    print('i am finished')


if __name__ == '__main__':
    my_urls = ['http://baidu.com/'] * 10 # Create a list of urls

    with ThreadPoolExecutor(max_workers=5) as pool:
        for page in pool.map(get_web_page, my_urls):
            # the submit(func, *args, **kwargs) method will schedule a callable to
            # be executed ( as func(*args, **kwargs)) and returns a Future object
            # that represents the execution of the callable
            fu = pool.submit(get_web_page, page)

            # Attach a callback function that will be executed (as fn(future))
            # when the scheduled callable returns
            fu.add_done_callback(finished)

            # Return True if the call is currently being executed and cannot be cancelled
            # print(fu.running())

            # Return True if the call was successfully cancelled or finished running
            # print(fu.done())

            # Attempt to cancel the call
            # print(fu.cancel())

            # Return True if the call was successfully cancelled
            # print(fu.cancelled())

            # Return the value returned by the call. Note that this call will block until t
            # he scheduled callable returns by default
            # print(fu.result())

            # Return the exception raised by the call. If no exception was raised
            # then this returns None. Note that this will block just like result().
            # print(fu.exception())

            print(page.text)
