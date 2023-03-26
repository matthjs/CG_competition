#include "model.ih"

/**
 * @brief Model::unpackIndexes Unpack indices so that they are available for
 * glDrawArrays()
 *
 */
void Model::unpackIndexes()
{
    vertices.clear();
    normals.clear();
    textureCoords.clear();
    for (int i = 0; i != indices.size(); ++i)
    {
        vertices.append(vertices_indexed[indices[i]]);

        if (hNorms)
            normals.append(norm[normal_indices[i]]);

        if (hTexs)
            textureCoords.append(tex[texcoord_indices[i]]);
    }
}