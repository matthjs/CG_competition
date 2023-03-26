#include "model.ih"

/**
 * @brief Model::meshTransform is a getter for d_meshTransform data member.
 */
QMatrix4x4 &Model::meshTransform()
{
    return d_meshTransform;
}