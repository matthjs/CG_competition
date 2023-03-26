#include "mainview.ih"

/**
 * @brief MainView::setScale Changes the scale of the displayed objects.
 * @param scale The new scale factor. A scale factor of 1.0 should scale the
 * mesh to its original size.
 */
void MainView::setScale(float newScale)
{
    d_scale = newScale;
    updateModelTransforms();
}