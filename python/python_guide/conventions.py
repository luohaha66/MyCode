def bad():
    d = {'hello': 'world'}
    if d.has_key('hello'):
        print(d['hello'])  # prints 'world'
    else:
        print('default_value')


def good():
    d = {'hello': 'world'}
    print(d.get('hello', 'default_value'))  # prints 'world'
    print(d.get('thingy', 'default_value'))  # prints 'default_value'
    # Or:
    if 'hello' in d:
        print(d['hello'])


# Never remove items from a list while you are iterating through it
def bad1(j=None):
    # Filter elements greater than 4
    a = [3, 4, 5]
    for i in a:
        if i > 4:
            a.remove(i)
    # Don’t make multiple passes through the list.
    while j in a:
        a.remove(j)


# Creating a new list requires more work and uses more memory. If you a just going to loop through the new list,
# consider using an iterator instead
def good1():
    # comprehensions create a new list object
    filtered_values = [value for value in range(5) if value != 1]

    # generators don't create another list
    filtered_values1 = (value for value in range(5) if value != 1)
    # Or (3.x)
    filtered_values2 = filter(lambda i: i != 5, range(5))
    print(filtered_values, filtered_values1, filtered_values2)

    # replace the contents of the original list
    sequence = [1, 2, 3]
    sequence1 = [1, 2, 3]
    sequence2 = [1, 2, 3]
    sequence[::] = [value for value in range(5) if value != 1]
    # Or
    sequence1[::] = (value for value in range(5) if value != 1)
    # Or
    sequence2[::] = filter(lambda value: value != 1, range(5))
    print(sequence, sequence1, sequence2)


# Modifying the values in a list
def bad2():
    # Add three to all list members.
    a = [3, 4, 5]
    b = a  # a and b refer to the same list object
    for i in range(len(a)):
        a[i] += 3  # b[i] also changes
    print(a, b)


def good2():
    a = [3, 4, 5]
    b = a
    # assign the variable "a" to a new list without changing "b"
    a = [i + 3 for i in a]
    # Or
    a = list(map(lambda i: i + 3, a))
    print(a, b)
    for i, item in enumerate(a):
        print(i, item)


# Read form a file
def read_file():
    # bad
    f = open('file.txt')
    a = f.read()
    print(a)
    f.close()
    # good
    # The with statement is better because it will ensure you always close the file, even if an exception
    # is raised inside the with block.
    with open('file.txt') as f:
        for line in f:
            print(line)


def line():
    # bad
    my_very_big_string = """For a long time I used to go to bed early. Sometimes, \
    when I had put out my candle, my eyes would close so quickly that I had not even \
    time to say “I’m going to sleep.”"""
    # good
    my_very_big_string = (
        "For a long time I used to go to bed early. Sometimes, "
        "when I had put out my candle, my eyes would close so quickly "
        "that I had not even time to say “I’m going to sleep.”"
    )
    print(my_very_big_string)


if __name__ == '__main__':
    ...
