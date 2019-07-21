size = 4
buff = [0 for each in range(size)]
start = end = 0


def put(buff, data):
    global end, start, size
    l1 = min(1, size - end + start)
    print(end)
    if l1:
        buff[end & (size - 1)] = data
        end += 1
    else:
        print('full')


def get(buff):
    global end, start, size
    l1 = min(1, end - start)
    if l1:
        print(buff[start & (size - 1)])
        start += 1
    else:
        print('empty')


put(buff, 0)
put(buff, 1)
put(buff, 2)
put(buff, 3)
put(buff, 4)
print(buff)
get(buff)
get(buff)
put(buff, 5)
put(buff, 6)
print(buff)