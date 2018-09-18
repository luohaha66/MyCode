strs = """aaaa,
bbbbb,
ccccc,\
"""
print(strs)
a=12
print(int(a))
print(str(a))
print(type(a))

a=int(input("input a number"))
if a==5:
    print("hello")
else:
    print("world", "welcome")
    
print(int(a) if int(a) < 4 else 5)
assert 4 > 3
while a < 5:
    print(a)
    a += 1
a=4
for a in range(0, 5, 1):
    a += 1
    print(a)

name = [112, "dsada", [1, (1, "adasd")]]
print(name)
name.append('cool')
print(name)
name.insert(0, 520)
print(name)
name.remove(112)
print(name)
del name[0]
print(name)