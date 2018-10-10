from contextlib import contextmanager


@contextmanager
def custom_open(filename):
    print('custom called')
    fs = open(filename)
    try:
        print(' yield')
        yield fs
        print('recovery')
    finally:
        fs.close()


class CustomOpen(object):
    def __init__(self, filename):
        print('init called')
        self.file = open(filename)

    def __enter__(self):
        print('enter called')
        return self.file

    def __exit__(self, ctx_type, ctx_value, ctx_traceback):
        print('exit called')
        self.file.close()


if __name__ == '__main__':
    with CustomOpen('requests.txt') as f:
        print('open called')
        contents = f.read()

    with custom_open('requests.txt') as f:
        print('terse open called')
        content = f.read()
