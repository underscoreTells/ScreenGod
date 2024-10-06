#include "../headers/shader_effect.h"

ShaderEffect::ShaderEffect(QOpenGLShaderProgram *shader) : shaderProgram(shader) {}

void ShaderEffect::apply() {
    shaderProgram->bind();
    // Apply shader effect logic
}

void ShaderEffect::remove() {
    shaderProgram->release();
}
