import numpy as np


print(np.nan == np.nan)

# statistic nan in numpy array
t1 = np.random.randint(10, 20, (3, 4)).astype(dtype=float)
print(t1)

t1[0, 0] = np.nan
print(t1)
print(np.count_nonzero(np.isnan(t1)))

# some useful statistic method
print(np.sum(t1, axis=0))
print(np.sum(t1, axis=1))
print(t1.mean(axis=0))
print(np.median(t1, axis=0))
print(t1.max(axis=0))
print(t1.min(axis=0))
print(np.ptp(t1, axis=0))
print(t1.std(axis=0))
