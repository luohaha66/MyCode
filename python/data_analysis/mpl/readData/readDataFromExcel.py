# -*- coding: UTF-8 -*-
"""
Created on Sep 21, 2018
@author: LWB
"""

import xlrd
import sys
import pprint
import datetime

if __name__ == '__main__':
    file_name = '1.xls'
    data = list()
    try:
        wb = xlrd.open_workbook(filename=file_name)
        ws = wb.sheet_by_name('Sheet1')
    except xlrd.XLRDError:
        print(xlrd.XLRDError.message)
        sys.exit()
    for r in range(ws.nrows):
        col = list()
        for c in range(ws.ncols):
            col.append(ws.cell(r, c).value)
        data.append(col)
    pprint.pprint(data)
    print('***************')
    # date
    cell = ws.cell(2, 0)
    if cell.ctype == xlrd.XL_CELL_DATE:
        date_value = xlrd.xldate_as_tuple(cell.value, wb.datemode)
        pprint.pprint(datetime.datetime(*date_value))
