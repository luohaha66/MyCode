import os
import shutil
import glob
import sys


def os_test():
    print(os.getcwd())
    os.system('start cmd')
    shutil.copyfile('errorDemo.py', 'ada.py')
    print(glob.glob('*.py'))
    sys.stderr.write('hahaha')
    sys.stdout.write('hahaha')


if __name__ == '__main__':
    import re
    print(re.findall(r'\bf[a-z]*', 'which foot or hand fell fastest'))
    print(re.sub(r'(\b[a-z]+) \1', r'\1', 'cat in the the hat'))
    print('tea for too'.replace('too', 'two'))
