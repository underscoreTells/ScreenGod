#ifndef SHADER_EFFECT_WIDGET_H
#define SHADER_EFFECT_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QImage>

class ShaderEffectWidget : public QOpenGLWidget {
private:
    Q_OBJECT
    QOpenGLShaderProgram *shaderProgram;
    QImage desktopImage;

protected:
    void initializeGL() override;
    void paintGL() override;

public:
    ShaderEffectWidget(QWidget *parent = nullptr);
};

#endif // SHADER_EFFECT_WIDGET_H
