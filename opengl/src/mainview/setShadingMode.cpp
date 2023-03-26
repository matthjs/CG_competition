#include "mainview.ih"

/**
 * @brief MainView::setShadingMode delegates shader switching to 
 * appropriate member functions.
 * @param shading
 */
void MainView::setShadingMode(ShadingMode shading)
{
    qDebug() << "Changed shading to" << shading;
    (this->*s_shaderSwitch[shading])();
}