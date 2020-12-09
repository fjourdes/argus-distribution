import os
import argus
import sys

_example = argus.EXAMPLE_DRAG_CLOTH

python_path = os.path.dirname(os.path.realpath(__file__))
argus_interface = os.path.join(python_path, 'argus_interface.py')

os.system('{} {} -e {}'.format(sys.executable, argus_interface, _example))