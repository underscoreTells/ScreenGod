#ifndef SHADER_EFFECT_H
#define SHADER_EFFECT_H

#include <QOpenGLShaderProgram>
#include "effect.h"

class ShaderEffect : public Effect {
private:
    QOpenGLShaderProgram *shaderProgram;

public:
    ShaderEffect(QOpenGLShaderProgram *shader);

    void apply() override;
    void remove() override;
};

#endif // SHADER_EFFECT_H
