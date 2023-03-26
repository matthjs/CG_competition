#include "model.ih"

/**
 * @brief Model::alignData
 *
 * Make sure that the indices from the vertices align with those
 * of the normals and the texture coordinates, create extra vertices
 * if vertex has multiple normals or texturecoords
 */
void Model::alignData()
{
    QVector<QVector3D> verts;
    verts.reserve(vertices_indexed.size());
    QVector<QVector3D> norms;
    norms.reserve(vertices_indexed.size());
    QVector<QVector2D> texcs;
    texcs.reserve(vertices_indexed.size());
    QVector<std::tuple<QVector3D, QVector3D, QVector2D>> vs;

    QVector<unsigned> ind;
    ind.reserve(indices.size());

    unsigned currentIndex = 0;

    for (int i = 0; i != indices.size(); ++i)
    {
        QVector3D v = vertices_indexed[indices[i]];

        QVector3D n(0, 0, 0);
        if (hNorms)
            n = norm[normal_indices[i]];

        QVector2D t(0, 0);
        if (hTexs)
            t = tex[texcoord_indices[i]];

        std::tuple<QVector3D, QVector3D, QVector2D> k(v, n, t);

        if (vs.contains(k))
            // Vertex already exists, use that index
            ind.append(vs.indexOf(k));
        else
        {
            // Create a new vertex
            verts.append(v);
            norms.append(n);
            texcs.append(t);
            vs.append(k);
            ind.append(currentIndex);
            ++currentIndex;
        }
    }

    // Remove old data
    vertices_indexed.clear();
    normals_indexed.clear();
    textureCoords_indexed.clear();
    indices.clear();

    // Set the new data
    vertices_indexed = verts;
    normals_indexed = norms;
    textureCoords_indexed = texcs;
    indices = ind;
}