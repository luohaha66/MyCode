# Code Listing #12

"""

Using generators, print details of the most recently modified file, matching a pattern.

"""

# pipe_recent_gen.py

import glob
import os
from time import sleep


def watch(pattern):
    """ Watch a folder for modified files matching a pattern """

    while True:
        files = glob.glob(pattern)
        # sort by modified time
        files = sorted(files, key=os.path.getmtime)
        recent = files[-1]
        yield recent
        # Sleep a bit
        sleep(1)


def get(inputs):
    """ For a given file input, print its meta data """

    for item in inputs:
        # data = os.popen("ls -lh " + item).read()
        yield item


if __name__ == "__main__":

    # Source
    stream1 = watch('*.txt')

    while True:
        # Filter
        stream2 = get(stream1)
        print(stream2.__next__())
        sleep(2)
