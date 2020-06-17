# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: c.py
* CREATED TIME: 2020/5/1 0001 19:30
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

# This imports all names except those beginning with an underscore (_)
# from tutorial.about_module.a import *

# There is a variant of the import statement that imports names
# from a module directly into the importing module’s symbol table
from tutorial.about_module.a import print_hello
from tutorial.about_module.b import print_world

# search path
# When a module named spam is imported, the interpreter first searches for a built-in module with that name. If
# not found, it then searches for a file named spam.py in a list of directories given by the variable sys.path.
# sys.path is initialized from these locations
# On file systems which support symlinks, the directory containing the input script is calculated after the symlink
# is followed. In other words the directory containing the symlink is not added to the module search path

if __name__ == '__main__':
    print_hello()
    print_world()
