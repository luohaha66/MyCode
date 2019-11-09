import pandas as pd
import numpy as np
import string

dt = pd.DataFrame(np.arange(12).reshape((3, 4)), index=list(string.ascii_uppercase[:3]),
                  columns=list(string.ascii_uppercase[:4]))
# print(dt)
# print(dt['A'])

dict1 = {'name': ['dog', 'pig'], 'age': [12, 13], 'sex': ['boy', 'girl']}
dt1 = pd.DataFrame(dict1)
# print(dt1)
# print(dt1.index)
# print(dt1.columns)
# print(dt1.values)
# print(dt1.ndim)
# print(dt1.head(1))
# print(dt1.tail(1))
# print(dt1.info())
# print(dt1.describe())
# print(dt1.sort_values(by='age'))

# get rows
# print(dt1[:1])
# get cols
# print(dt1['name'])
# print(dt1.loc[0, 'name'])
# print(dt1.loc[0])
# print(dt1.loc[:, ['age', 'name']])
#
# print(dt1.iloc[0])
# print(dt1.iloc[:, [0, 2]])

# print(dt1[(dt1['age'] > 12) & (dt1['age'] < 20)])
# dt1['age'] = np.nan
# print(pd.isnull(dt1))
# print(dt1.dropna(axis=1, how='all', inplace=False))
# print(dt1.fillna(15))

# print(dt.join(dt1))
# print(dt.erge(dt1, how='outer'))
dt3 = dt1.groupby(by=['age', 'sex']).count()
print(dt3)
# multiIndex
print(dt3.index)
# print(dt1[['age']])
