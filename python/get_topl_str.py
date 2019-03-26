import re


def replace(r_str, o_str):
    return re.sub(rf'{r_str}.*?\s', f'{r_str} ', o_str)


if __name__ == '__main__':
    str_list = ['/aa/bb/cc', '/aa/ff/ee', '/aa/bb', '/aa/ff', '/dd', '/dd/ee', '/ff/aa', '/ff', '/aaa/ddd/eee',
                '/aaa/fff', '/aaa/fff/eee', '/aaa/ccc']
    path = f'{str_list[0]} '
    for each in str_list:
        path = replace(each, path)
        if each not in path:
            exist = False
            for e in path.split(' '):
                if e and each[0: len(e)] == e:
                    exist = True
                    break
            if not exist:
                path = f'{path}{each} '
    print(path)
