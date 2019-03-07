import collections

if __name__ == '__main__':
    # memory efficient, read only
    Employee = collections.namedtuple('Employee', 'name, age, gender')
    luo = Employee(name='luo', age='25', gender='wei')
    for filed in luo:
        print(filed)
    print(luo.name)
