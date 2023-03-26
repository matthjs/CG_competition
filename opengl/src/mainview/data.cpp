#include "mainview.ih"

// static data

// array of pointers to member function of mainview
// used in setShadingMode.cpp
void (MainView::*MainView::s_shaderSwitch[])() =
{
    &MainView::phongShading,
    &MainView::normalShading,
    &MainView::gouraudShading,
    &MainView::cellShading
};
