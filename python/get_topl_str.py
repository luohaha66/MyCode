import re


def replace(r_str, o_str):
    return re.sub(rf'{r_str}/.*?\s', f'{r_str} ', o_str)


if __name__ == '__main__':
    path = '/aa/bb/cc '
    str_list = ['/aa/ff/ee', '/aa/bb', '/aa/ff', '/dd', '/dd/ee', '/ff/aa', '/ff', '/www/ddd/eee',
                '/www/ww/fff', '/ww', '/www/fff/eee', '/aaa/ccc']
    for each in str_list:
        path = replace(each, path)
        if not re.search(rf'{each}/', path):
            exist = False
            for e in path.split(' '):
                if e and re.search(rf'^{e}/', each):
                    exist = True
                    break
            if not exist:
                path = f'{path}{each} '
        # print(path)
    print(set(path.split(' ')))
