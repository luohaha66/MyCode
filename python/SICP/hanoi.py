def hanoi(n, src, tmp, dest):
    if n == 0:
        return None
    if n == 1:
        move(src, dest)
        return
    else:
        hanoi(n - 1, src, dest, tmp)
        move(src, dest)
        hanoi(n - 1, tmp, src, dest)


def move(src, dest):
    print(src, '->', dest)


if __name__ == '__main__':
    hanoi(3, 'SRC', 'TMP', 'DEST')
