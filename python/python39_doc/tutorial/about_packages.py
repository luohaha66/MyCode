# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_packages.py
* CREATED TIME: 2020/5/14 0014 14:40
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

"""
The __init__.py files are required to make Python treat directories containing the file as packages.
This prevents directories with a common name, such as string, unintentionally hiding valid modules
that occur later on the module search path. In the simplest case, __init__.py can just be an empty file,
but it can also execute initialization code for the package or set the __all__ variable, described later

Note that when using from package import item, the item can be either a submodule (or subpackage) of
the package, or some other name defined in the package, like a function, class or variable. The import statement
first tests whether the item is defined in the package; if not, it assumes it is a module and attempts to load it.
If it fails to find it, an ImportError exception is raised.
Contrarily, when using syntax like import item.subitem.subsubitem, each item except for the last must
be a package; the last item can be a module or a package but can’t be a class or function or variable defined in the
previous item

if a package’s __init__.py code defines a list named __all__, it is taken to
be the list of module names that should be imported when from package import * is encountered

If __all__ is not defined, the statement from sound.effects import * does not import all submodules
from the package sound.effects into the current namespace; it only ensures that the package sound.effects
has been imported (possibly running any initialization code in __init__.py) and then imports whatever names
are defined in the package

Remember, there is nothing wrong with using from package import specific_submodule! In fact,
this is the recommended notation unless the importing module needs to use submodules with the same name from
different packages
"""

if __name__ == '__main__':
    ...
