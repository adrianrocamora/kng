import os
from solid import *
from solid.utils import *

d = cube(5) + right(5)(sphere(5)) - cylinder(r=2, h=6)
print(scad_render(d))

directory = os.path.dirname(__file__)
shape_scad = os.path.join(directory, 'shape') + '.scad'
shape_stl = os.path.join(directory, 'shape') + '.stl'
# scad_render_to_file(d, shape_scad)
scad_render_to_file(d, shape_scad, file_header='$fn = 100;')
# TODO: add calls for *nix systems"
os.system('openscad.com -o ' +
          shape_stl +
          ' '  +
          shape_scad)
