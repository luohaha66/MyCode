import pybloom_live
import requests

if __name__ == '__main__':
    texts = requests.get('http://www.gutenberg.org/files/2852/2852-0.txt')
    bloom = pybloom_live.BloomFilter(capacity=10000, error_rate=0.1)
    for each in texts.text.split():
        bloom.add(each)

    print(len(bloom))
    print('the' in bloom)
    print('luo_wei_' not in bloom)
