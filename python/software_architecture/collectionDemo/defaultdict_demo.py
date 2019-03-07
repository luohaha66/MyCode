import collections as cl


def cities_same_len():
    """
    0 - default value for int
    '' - default value for str
    [] - default value for list
    {} - default value for dict
    :return:
    """
    cities = ['chengdu', 'chongqing', 'shanghai', 'hongkong']
    cities_len = cl.defaultdict(list)
    for city in cities:
        cities_len[len(city)].append(city)
    return cities_len


if __name__ == '__main__':
    print(cities_same_len())
