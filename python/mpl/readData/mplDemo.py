"""
Created on Sep 21, 2018
@author: LWB
"""
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

if __name__=='__main__':
    t = np.arange(0.0, 1.0, 0.01)
    s = np.sin(2 * np.pi * t)
    # make line red
    plt.rcParams['lines.color'] = 'r'
    c = np.cos(2 * np.pi * t)
    # make line thick
    plt.rcParams['lines.linewidth'] = '3'
    plt.plot(t, c)
    plt.show()
    print(mpl.get_configdir())
