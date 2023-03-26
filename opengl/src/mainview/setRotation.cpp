#include "mainview.ih"

/**
 * @brief MainView::setRotation Changes the rotation of the displayed objects.
 * @param rotateX Number of degrees to rotate around the x axis.
 * @param rotateY Number of degrees to rotate around the y axis.
 * @param rotateZ Number of degrees to rotate around the z axis.
 */
void MainView::setRotation(int rotateX, int rotateY, int rotateZ)
{
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << ","
            << rotateZ << ")";

    d_rotation = {static_cast<float>(rotateX), static_cast<float>(rotateY),
                static_cast<float>(rotateZ)};

    updateModelTransforms();
}