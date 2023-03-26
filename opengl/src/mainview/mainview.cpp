#include "mainview.ih"

/**
 * @brief MainView::MainView Constructs a new main view.
 *
 * @param parent Parent widget.
 * IMPORTANT: allocates space for (+initializes) 3 uniformMaps (for 3 shaders), can be adjusted.
 */
MainView::MainView(QWidget *parent)
:
    QOpenGLWidget(parent)
{
    qDebug() << "MainView constructor";

    d_shaderUniforms.resize(4);    // 4 shaders for now (adjust when needed)

    connect(&d_timer, SIGNAL(timeout()), this, SLOT(update()));
}
