# Code Listing #5

"""

A simple web client using Twisted

"""

# twisted_fetch_url.py
from twisted.internet import reactor
from twisted.web.client import getPage
import treq
import sys


def save_page(page):
    print(page)


def handle_error(error):
    print(error)


def finish_processing(value):
    print("Shutting down...")
    reactor.stop()


if __name__ == "__main__":
    deferred = getPage(bytes('https://www.baidu.com/?tn=62095104_9_oem_dg', encoding='utf-8'))
    deferred.addCallbacks(save_page, handle_error)
    deferred.addBoth(finish_processing)
    # deferred = treq.get('https://www.baidu.com/?tn=62095104_9_oem_dg')
    # deferred.addCallbacks(save_page, handle_error)
    # deferred.addBoth(finish_processing)
    reactor.run()
