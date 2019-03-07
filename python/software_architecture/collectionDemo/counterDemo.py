import collections
import requests


if __name__ == '__main__':
    texts = requests.get('http://www.gutenberg.org/files/2852/2852-0.txt')

    freq = collections.Counter(filter(None, map(lambda x: x.lower().strip(), texts.text.split())))
    print(freq.most_common(10))
