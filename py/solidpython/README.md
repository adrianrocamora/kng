# Call OpenSCAD from the command line

We use [SolidPython](https://github.com/SolidCode/SolidPython) here to generate SCAD code. This has the following advantages:
* built-in dictionary types
* mutable, slice-able list and string types
* recursion
* external libraries (images! 3D geometry! web-scraping! ...)


## Windows

```
openscad.com -o cube_minus_sphere.stl .\cube_minus_sphere.scad
```

## General options
```
openscad     [ -o output_file [ -d deps_file ] ]\
             [ -m make_command ] [ -D var=val [..] ] \
             [ --help ] print this help message and exit \
             [ --version ] [ --info ] \
             [ --camera=translatex,y,z,rotx,y,z,dist | \
               --camera=eyex,y,z,centerx,y,z ] \
             [ --autocenter ] \
             [ --viewall ] \
             [ --imgsize=width,height ] [ --projection=(o)rtho|(p)ersp] \
             [ --render | --preview[=throwntogether] ] \
             [ --colorscheme=[Cornfield|Sunset|Metallic|Starnight|BeforeDawn|Nature|DeepOcean] ] \
             [ --csglimit=num ]\
             filename
```

https://en.wikibooks.org/wiki/OpenSCAD_User_Manual/Using_OpenSCAD_in_a_command_line_environment
