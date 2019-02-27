# -*- coding: UTF-8 -*-
"""
Created on Sep 21, 2018
@author: LWB
"""

import csv
import sys
import pprint

if __name__ == '__main__':
    file_name = '1.csv'
    data = list()
    try:
        with open(file_name, 'r') as f:
            reader = csv.reader(f)
            data = [row for row in reader]
    except csv.Error:
        print(csv.Error.message)
        sys.exit()
    for data_row in data:
        pprint.pprint(data_row)
