# create a concatenated string from 0 to 19 (e.g. "012..1819")
def bad():
    nums = ""
    for n in range(20):
        nums += str(n)  # slow and inefficient
    print(nums)


def good():
    nums = []
    for n in range(20):
        nums.append(str(n))
    print("".join(nums))  # much more efficient


def better():
    nums = [str(n) for n in range(20)]
    print("".join(nums))


def best():
    nums = map(str, range(20))
    print("".join(nums))


# creating a new string with exists string, the method join is not always the best choices.
def normal_exist():
    foo = 'foo'
    bar = 'bar'
    foobar = foo + bar  # This is good
    print(foobar)
    # foo += 'ooo'  # This is bad, instead you should do:
    foo = ''.join([foo, 'ooo'])
    print(foo)


def normal_exist_1():
    foo = 'foo'
    bar = 'bar'
    foobar = '%s%s' % (foo, bar)  # It is OK
    print(foobar)
    foobar1 = '{0}{1}'.format(foo, bar)  # It is better
    print(foobar1)
    foobar2 = '{foo}{bar}'.format(foo=foo, bar=bar)  # It is best
    print(foobar2)


if __name__ == '__main__':
    bad()
    good()
    better()
    best()
    normal_exist()
    normal_exist_1()
