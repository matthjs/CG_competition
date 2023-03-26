#include "mainview.ih"

/**
 * @brief MainView::updateProjectionTransform Updates the projection transform
 * matrix taking into consideration the current aspect ratio.
 */
void MainView::updateProjectionTransform()
{
    float aspectRatio =
        static_cast<float>(width()) / static_cast<float>(height());
    d_projectionTransform.setToIdentity();
    d_projectionTransform.perspective(60.0F, aspectRatio, 0.2F, 20.0F);
}