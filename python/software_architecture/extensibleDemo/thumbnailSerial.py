from PIL import Image
import urllib.request
import datetime


def thumbnail(url, size=(64, 64), formats='.png'):
    """save thumbnail for an image URL"""
    img = Image.open(urllib.request.urlopen(url))

    # get filename
    pieces = url.split('/')
    filename = '{}_{}{}'.format(pieces[-2], pieces[-1].split('.')[0], formats)
    img.thumbnail(size, Image.ANTIALIAS)
    img.save(filename)
    print('saved', filename)


# cost_time = 36.57s
if __name__ == '__main__':
    a = datetime.datetime.now()
    urls = [
        'https://dummyimage.com/256/000/fff.jpg',
        'https://dummyimage.com/320/fff/000.jpg',
        'https://dummyimage.com/640/ccc/aaa.jpg',
        'https://dummyimage.com/128/ddd/eee.jpg'
    ]

    for url in urls:
        thumbnail(url)
    print('cost time', datetime.datetime.now() - a)
