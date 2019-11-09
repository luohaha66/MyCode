import numpy as np


t1 = np.arange(12).reshape((3, 4))
t2 = np.arange(12, 24).reshape((3, 4))

print(np.vstack((t1, t2)))
print(np.hstack((t1, t2)))

# swap cols and rows
t1[[0, 2], :] = t1[[2, 0], :]
print(t1)

