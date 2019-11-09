import pandas as pd
import string

t = pd.Series([1, 2, 3], index=list(string.ascii_uppercase[:3]))
print(t)

t = pd.Series({string.ascii_uppercase[i]: i for i in range(10)})
print(t)

print(t['A'])
print(t[0])
print(t[:3])
print(t[[5, 6]])
print(t[['A', 'B']])
print(t[t < 5])
print(t.index)
print(t.values)
print(t.where(t > 5, 666))
