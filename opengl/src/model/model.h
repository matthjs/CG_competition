#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QStringList>
#include <QVector2D>
#include <QVector3D>
#include <QVector>
#include <QMatrix4x4>
#include <QMatrix3x3>
#include <GL/gl.h>
#include <QImage>
#include "../abstractmodel/abstractmodel.h"
#include "../vertex/vertex.h"

/**
 * @brief A simple Model class. Represents a 3D triangle mesh and is able to
 * load this data from a Wavefront .obj file. IMPORTANT: Current only supports
 * TRIANGLE meshes!
 *
 */
class Model: public AbstractModel
{
    // Added
    QVector<Vertex> d_complete_vertices;
    QMatrix4x4 d_meshTransform;
    QMatrix3x3 d_normalTransform;
    QMatrix4x4 d_unitize;

    GLuint d_VBO;
    GLuint d_VAO;
    GLuint d_textureID;
    QImage d_texture;

    QVector<GLuint> d_textureIDs;
    QVector<QImage> d_textures;

    // Intermediate storage of values
    QVector<QVector3D> vertices_indexed;
    QVector<QVector3D> normals_indexed;
    QVector<QVector2D> textureCoords_indexed;
    QVector<unsigned> indices;

    QVector<QVector3D> vertices;
    QVector<QVector3D> normals;
    QVector<QVector2D> textureCoords;

    // Utility storage
    QVector<unsigned> normal_indices;
    QVector<unsigned> texcoord_indices;
    QVector<QVector3D> norm;
    QVector<QVector2D> tex;

    bool hNorms = false;
    bool hTexs = false;
    
    public:
        Model() = delete;
        Model(QString const &filename);

        // overwritten from abstract model
        ~Model() override;
        QMatrix4x4 &meshTransform() override;
        QMatrix3x3 &normalTransform() override;
        QVector<Vertex> &getVertices() override;

        GLuint &VBO() override;
        GLuint &VAO() override;
    
        GLuint &textureID() override;
        void setTexture(QImage const &image) override;
        QVector<quint8> textureData() const override;
        QImage const &texture() const override;

        GLuint &textureID(size_t idx) override;
        GLuint &enableTextureID() override;
        void addTexture(QString const &textureNames) override;
        QVector<quint8> textureData(size_t idx) const override;
        QImage const &texture(size_t idx) const override;

        size_t numTextures() const override; 
        bool hasTexture() const override;
        bool hasNormals() const override;

        // Used for glDrawArrays()
        QVector<QVector3D> getCoords();
        QVector<QVector3D> getNormals();
        QVector<QVector2D> getTextureCoords();

        // Used for interleaving into one buffer for glDrawArrays()
        QVector<float> getVNInterleaved();
        QVector<float> getVNTInterleaved();

        // Used for glDrawElements()
        QVector<QVector3D> getCoordsIndexed();
        QVector<QVector3D> getNormalsIndexed();
        QVector<QVector2D> getTextureCoordsIndexed();
        QVector<unsigned> getIndices();

        // Used for interleaving into one buffer for glDrawElements()
        QVector<float> getVNInterleavedIndexed();
        QVector<float> getVNTInterleavedIndexed();

        bool hasNormals();
        bool hasTextureCoords();
        int getNumTriangles();
        int meshSize();

        void unitize();

    private:
        void initializeVertices();

        // OBJ parsing
        void parseVertex(QStringList tokens);
        void parseNormal(QStringList tokens);
        void parseTexture(QStringList tokens);
        void parseFace(QStringList tokens);

        // Alignment of data
        void alignData();
        void unpackIndexes();
};

#endif  // MODEL_H

inline size_t Model::numTextures() const
{
    return d_textures.size();
}

/**
 * @brief Model::getCoords Get all coordinates in the mesh. The coordinates are
 * ordered in such a way that they can be used in glDrawArrays. For a mesh
 * consisting of two triangles, this might look as follows: c1, c2, c3, c2,
 * c3, c4, etc.
 * @return The coordinates in the mesh.
 */
inline QVector<QVector3D> Model::getCoords()
{
    return vertices;
}

/**
 * @brief Model::getCoords Get all normals in the mesh. The normals are
 * ordered in such a way that they can be used in glDrawArrays. For a mesh
 * consisting of two triangles, this might look as follows: n1, n2, n3, n2, n3,
 * n4, etc.
 * @return The normals in the mesh.
 */
inline QVector<QVector3D> Model::getNormals()
{
    return normals;
}

/**
 * @brief Model::getCoords Get all texture coordinates in the mesh. The texture
 * coordinates are ordered in such a way that they can be used in glDrawArrays.
 * For a mesh consisting of two triangles, this might look as follows: tx1, tx2,
 * tx3, tx2, tx3, tx4, etc.
 * @return The texture coordinates in the mesh.
 */
inline QVector<QVector2D> Model::getTextureCoords()
{
    return textureCoords;
}

/**
 * @brief Model::getCoords Get all unique coordinates in the mesh. The
 * coordinates are ordered in such a way that they can be used in
 * glDrawElements. For a mesh consisting of two triangles, this might look as
 * follows: c1, c2, c3, c4. Intended to be used in combination with
 * getIndices().
 * @return The unique coordinates in the mesh.
 */
inline QVector<QVector3D> Model::getCoordsIndexed()
{
    return vertices_indexed;
}

/**
 * @brief Model::getCoords Get all unique normals in the mesh. The
 * normals are ordered in such a way that they can be used in
 * glDrawElements. For a mesh consisting of two triangles, this might look as
 * follows: n1, n2, n3, n4. Intended to be used in combination with
 * getIndices().
 * @return The unique normals in the mesh.
 */
inline QVector<QVector3D> Model::getNormalsIndexed()
{
    return normals_indexed;
}

/**
 * @brief Model::getCoords Get all unique texture coordinates in the mesh. The
 * texture coordinates are ordered in such a way that they can be used in
 * glDrawElements. For a mesh consisting of two triangles, this might look as
 * follows: tx1, tx2, tx3, tx4. Intended to be used in combination with
 * getIndices().
 * @return The unique texture coordinates in the mesh.
 */
inline QVector<QVector2D> Model::getTextureCoordsIndexed()
{
    return textureCoords_indexed;
}

/**
 * @brief Model::getIndices Retrieves a list of indices in such a way that these
 * describe the topology of the mesh. In other words, these indices describe how
 * the given (unique) coordinates/normals/texture coordinates make up all the
 * different triangles in the mesh. Intended to be used with glDrawElements.
 * @return A list of indices.
 */
inline QVector<unsigned> Model::getIndices()
{
    return indices;
}

/**
 * @brief Model::getNumTriangles Retrieves the number of triangles in this mesh.
 * @return The number of triangles in this mesh.
 */
inline int Model::getNumTriangles()
{
    return vertices.size() / 3;
}

/**
 * @brief Model::meshSize() returns the mesh size
 * measured by the number of vertices.
 */
inline int Model::meshSize()
{
    return vertices.size();
}
