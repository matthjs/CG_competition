#include "mainview.ih"

/**
 * @brief MainView::~MainView
 *
 * Destructor of MainView
 * This is the last function called, before exit of the program
 * Use this to clean up your variables, buffers etc.
 *
 */
MainView::~MainView()
{
    qDebug() << "MainView destructor";

    destroyModelBuffers();

    makeCurrent();
}