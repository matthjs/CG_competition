# CG_competition

This repository contains my OpenGL submission for the competition in the computer graphics course.
Currently the main things that is added is basic cell shading, which you can enable
in the UI alongside the other shaders (note that the gouraud shading does not load any texture data).
The other addition is adding anisotropic filtering.
It is worth noting that the code already supports multiple model loading, however all models are
not unitized and are all fixed on the same location in world space.

There are also a few fixes made from the base code:
- Optimized model rendering by loading static mesh data in initializeGL
    (before render loop), instead of in paintGL (during render loop)
    (which in hindsight was kind of obvious to do so).
- Improved efficiency of shader switching by ensuring that uniforms are extracted only the
    first time the shader is loaded.

Compiling the code:
I do not use QTCREATOR so I will describe here how to build the project using the
existing build utilities.
In the src directory do:
- run "cmake CMakeLists.txt" to generate the Makefile
- run "make"
- run "./OpenGL"

# Showcase
Here is how the cat model looks like using cell shading:
!["Cat with cell shading."](./opengl/src/logs/cat_cell.png)

Cell-shading is commonly used in anime-style games/3d animations to
replicate the style and feel of the 2D drawings. So here is an
example of cell shading on an anime character:
!["Emilia from Re Zero with cell shading."](./opengl/src/logs/emilia_cell_text.png)
which fits a bit better than the phong illumination:
!["Emilia from Re Zero with phong shading."](./opengl/src/logs/emilia_phong_text.png)
(Note that the texture mapping is not correct)


Unrelated. But when you normalize all vertices on the cat model you
get this monstrosity:
!["Uhhhhh"](./opengl/src/logs/catt_phong.png)
(note that Phong shader is used here)'

# Update
Added support for multiple textures (around 27-03-2023)
