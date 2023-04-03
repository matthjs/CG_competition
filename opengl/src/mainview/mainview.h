#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

#include "../shadingmode/shadingmode.h"
#include "../abstractmodel/abstractmodel.h"

/**
 * @brief The MainView class is resonsible for the actual content of the main
 * window.
 */
class MainView: public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    using uniformMap = std::unordered_map<QString, std::unique_ptr<GLint>>;

    // shader related
    static void (MainView::*s_shaderSwitch[])();   // used for shader switching
    std::vector<uniformMap> d_shaderUniforms;
    ShadingMode d_currentShadingMode;

    // perspective projection transformation (fixed)
    QMatrix4x4 d_projectionTransform;

    // polymorphic models
    std::vector<std::unique_ptr<AbstractModel>> d_models;

    // extra values that need to be keeped track of
    float d_scale = 1.0F;
    QVector3D d_rotation;

    // OpenGL stuff
    Q_OBJECT
    QOpenGLDebugLogger d_debugLogger;
    QTimer d_timer;        // timer used for animation
    QOpenGLShaderProgram d_shaderProgram;

    public:
        MainView(QWidget *parent = nullptr);
        ~MainView() override;

        // Functions for widget input events
        void setRotation(int rotateX, int rotateY, int rotateZ);
        void setScale(float scale);
        void setShadingMode(ShadingMode shading);    // TBA

    protected:
        void initializeGL() override;
        void paintGL() override;
        void resizeGL(int newWidth, int newHeight) override;

        // Functions for keyboard input events
        void keyPressEvent(QKeyEvent *ev) override;
        void keyReleaseEvent(QKeyEvent *ev) override;

        // Function for mouse input events
        void mouseDoubleClickEvent(QMouseEvent *ev) override;
        void mouseMoveEvent(QMouseEvent *ev) override;
        void mousePressEvent(QMouseEvent *ev) override;
        void mouseReleaseEvent(QMouseEvent *ev) override;
        void wheelEvent(QWheelEvent *ev) override;

    private slots:
        void onMessageLogged(QOpenGLDebugMessage Message);

    private:
        void createShaderProgram();
        void loadMesh(QString const &filename, QString const &textureFileName);    // 1
        void loadMesh(QString const &filename, QVector<QString> const &textureNames); // 2

        // update transformation matrices based on relevant events
        void updateProjectionTransform();
        void updateModelTransforms(); 

        void destroyModelBuffers();    // run by destructor

        // texture related
        void setTextureInterpretation();
        void initializeSamplers(size_t numTextures);
        void uploadTextureData(QImage const &texture);

        // shading related -> addresses are placed in s_shaderswitch (see data.cc)
        void phongShading();
        void normalShading();
        void gouraudShading();
        void cellShading();
};

/**
 * @brief MainView::onMessageLogged OpenGL logging function, do not change.
 *
 * @param Message The message to be logged.
 */
inline void MainView::onMessageLogged(QOpenGLDebugMessage Message)
{
    qDebug() << " → Log:" << Message;
}

#endif  // MAINVIEW_H
