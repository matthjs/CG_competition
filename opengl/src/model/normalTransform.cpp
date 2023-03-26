#include "model.ih"

/**
 * @brief Model::normalTransform is a getter for d_normalTransform.
 */
QMatrix3x3 &Model::normalTransform()
{
    return d_normalTransform;
}