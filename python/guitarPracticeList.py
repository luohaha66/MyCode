import itertools
import random
import json


if __name__ == '__main__':
    guitar = [1, 2, 3, 4, 5, 6]
    rank = list(itertools.permutations(guitar, 6))
    random_list = [random.randint(0, 719) for each in range(100)]
    practice = [str(rank[random_list[each]]) for each in range(100)]
    practice_json = {'practice': practice}

    with open('./guitar.json', 'w') as f:
        json.dump(practice_json, f)
