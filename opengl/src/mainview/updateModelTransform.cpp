#include "mainview.ih"

/**
 * @brief MainView::updateModelTransforms Updates the model transform matrix of
 * the mesh to reflect the current rotation and scale values.
 * NOTE: resets object location to (0, 0, -10)
 */
void MainView::updateModelTransforms()
{
    for (auto &model : d_models)
    {
        model->meshTransform().setToIdentity();
        model->meshTransform().translate(0.0F, 0.0F, -10.0F);
        model->meshTransform().rotate(QQuaternion::fromEulerAngles(d_rotation));
        model->meshTransform().scale(d_scale);

        model->normalTransform() = model->meshTransform().normalMatrix();
    }

    update();
}