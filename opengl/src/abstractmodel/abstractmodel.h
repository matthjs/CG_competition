#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QVector>
#include <QMatrix4x4>
#include <QString>
#include <GL/gl.h>
#include "../vertex/vertex.h"

/**
 * @brief Abstract Base Class Model objects.
 * It is used for polymorphism in paintGL and other member functions
 * in MainView.
 */
class AbstractModel
{
    public:
        AbstractModel() = default;

        // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c67-a-polymorphic-class-should-suppress-public-copymove
        AbstractModel(AbstractModel const &other) = delete;
        AbstractModel(AbstractModel &&tmp) = delete;
        AbstractModel &operator=(AbstractModel const &other) = delete;
        AbstractModel &operator=(AbstractModel &&tmp) = delete;

        virtual ~AbstractModel();

        // getters for VAO and VBO
        virtual GLuint &VBO() = 0;
        virtual GLuint &VAO() = 0;
        
        // redundant single texture case still here
        virtual GLuint &textureID() = 0;
        virtual void setTexture(QImage const &image) = 0;
        virtual QVector<quint8> textureData() const = 0;
        virtual QImage const &texture() const = 0;

        // general case here
        virtual GLuint &textureID(size_t idx) = 0;
        virtual GLuint &enableTextureID() = 0;
        virtual void addTexture(QString const &textureName) = 0;
        virtual QVector<quint8> textureData(size_t idx) const = 0;
        virtual QImage const &texture(size_t idx) const = 0;

        // required getters
        virtual QMatrix4x4 &meshTransform() = 0;
        virtual QMatrix3x3 &normalTransform() = 0;
        virtual QVector<Vertex> &getVertices() = 0;

        // good to know
        virtual size_t numTextures() const = 0;
        virtual bool hasTexture() const = 0;
        virtual bool hasNormals() const = 0;
};

#endif
