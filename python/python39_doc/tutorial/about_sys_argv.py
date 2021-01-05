# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_sys_argv.py
* CREATED TIME: 2020/4/8 0008 16:51
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

"""
The length of the list is at least one; when no script and no arguments are given, sys.argv[0] is an empty string.
When the script name is given as '-' (meaning standard input), sys.argv[0] is set to '-'. When -c command
is used, sys.argv[0] is set to '-c'. When -m module is used, sys.argv[0] is set to the full name of the
located module. Options found after -c command or -m module are not consumed by the Python interpreter’s option
processing but left in sys.argv for the command or module to handle
"""

if __name__ == '__main__':
    import sys
    # python -m about_sys_argv hello world
    print(sys.argv[0])  # D:\MyCode\python\python39_doc\tutorial\about_sys_argv.py
    print(sys.argv[1])  # hello
