# QT Documentation suggest 3.16
cmake_minimum_required(VERSION 3.16)

project(OpenGL_2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)   # fixes some issue
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

if (COMMAND qt_standard_project_setup)
    qt_standard_project_setup()
else()
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
endif()

set(CMAKE_AUTORCC ON)

qt_add_executable(OpenGL WIN32 MACOSX_BUNDLE
    resources.qrc
    mainwindow.ui
    main.cpp

    abstractmodel/abstractmodel.h
    abstractmodel/abstractmodel.ih
    abstractmodel/destructor.cpp

    mainview/mainview.h
    mainview/mainview.ih
    mainview/createShaderProgram.cpp
    mainview/destroyModelBuffers.cpp
    mainview/destructor.cpp
    mainview/initializeGL.cpp
    mainview/loadMesh1.cpp
    mainview/loadMesh2.cpp
    mainview/mainview.cpp
    mainview/paintGL.cpp
    mainview/resizeGL.cpp
    mainview/setRotation.cpp
    mainview/setScale.cpp
    mainview/setShadingMode.cpp
    mainview/updateModelTransform.cpp
    mainview/updateProjectionTransform.cpp
    mainview/userinput.cpp
    mainview/data.cpp
    mainview/gouraudShading.cpp
    mainview/normalShading.cpp
    mainview/phongShading.cpp
    mainview/cellShading.cpp
    mainview/loadMesh2.cpp
    mainview/setTextureInterpretation.cpp
    mainview/uploadTextureData.cpp
    
    mainwindow/mainwindow.h
    mainwindow/mainwindow.ih
    mainwindow/mainwindow.cpp
    mainwindow/destructor.cpp
    mainwindow/renderToFile.cpp
    mainwindow/on_ResetRotationButton_clicked.cpp
    mainwindow/on_RotationDialX_valueChanged.cpp
    mainwindow/on_RotationDialY_valueChanged.cpp
    mainwindow/on_RotationDialZ_valueChanged.cpp
    mainwindow/on_ResetScaleButton_clicked.cpp
    mainwindow/on_ScaleSlider_valueChanged.cpp
    mainwindow/on_GouraudButton_toggled.cpp
    mainwindow/on_NormalButton_toggled.cpp
    mainwindow/on_PhongButton_toggled.cpp
    mainwindow/on_CellButton_toggled.cpp

    
    model/model.h
    model/model.ih
    model/alignData.cpp
    model/destructor.cpp
    model/getVNInterleaved.cpp
    model/getVNInterleavedIndexed.cpp
    model/initializeVertices.cpp
    model/meshTransform.cpp
    model/model.cpp
    model/parseFace.cpp
    model/parseNormal.cpp
    model/parseTexture.cpp
    model/parseVertex.cpp
    model/unitize.cpp
    model/unpackIndexes.cpp
    model/vao.cpp
    model/vbo.cpp
    model/vertices.cpp
    model/normalTransform.cpp
    model/hasTexture.cpp
    model/hasNormals.cpp
    model/model2.cpp

    model/setTexture.cpp
    model/texture.cpp
    model/textureData.cpp
    model/textureID.cpp

    vertex/vertex.h
    vertex/vertex.ih
    vertex/vertex1.cpp
    vertex/vertex2.cpp
    vertex/getTextureCoords.cpp

    shadingmode/shadingmode.h

    utility/utility.cpp
    utility/utility.h
    utility/utility.ih

    resources.qrc
    mainwindow.ui
    main.cpp
)

target_include_directories(OpenGL PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(OpenGL PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGL
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
)

# This is used for interoperability, do not remove even on linux;
# On linux, result is an executable;
# On Windows, result is a Win32 executable, instead of console executable, command prompt window is not created;
# On MacOS, result is executable bundle;
set_target_properties(OpenGL PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
