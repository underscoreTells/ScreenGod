#include "../headers/overlay_window.h"
#include <QApplication>
#include <QScreen>
#include <cstdlib>  // For rand()

OverlayWindow::OverlayWindow() {
    // Create the shader and video effects
    shaderEffect = new ShaderEffect(new QOpenGLShaderProgram(this));
    videoEffect = new VideoEffect();
    
    commandManager = new CommandManager();
    currentEffect = nullptr;

    // Set window properties
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
    setGeometry(QApplication::primaryScreen()->geometry());
}

void OverlayWindow::initializeGL() {
    shaderEffect->apply();  // Initialize the shader program
}

void OverlayWindow::paintGL() {
    if (currentEffect) {
        currentEffect->apply();  // Apply the current effect during rendering
    }
}

void OverlayWindow::triggerRandomEffect(int durationMs) {
    int randomEffect = rand() % 2;  // Randomly choose between shader (0) and video (1)

    ApplyEffectCommand *effectCommand;
    if (randomEffect == 0) {
        effectCommand = new ApplyEffectCommand(shaderEffect);  // Apply shader
    } else {
        effectCommand = new ApplyEffectCommand(videoEffect);   // Apply video
    }

    commandManager->executeCommand(effectCommand);
    currentEffect = (randomEffect == 0) ? static_cast<Effect*>(shaderEffect) : static_cast<Effect*>(videoEffect);
    
    update();  // Repaint the window with the effect applied

    // Set up a timer to revert the effect after a certain duration
    effectTimer.singleShot(durationMs, this, &OverlayWindow::revertToNormal);
}

void OverlayWindow::revertToNormal() {
    if (currentEffect) {
        currentEffect->remove();  // Remove the current effect
        currentEffect = nullptr;
        update();  // Repaint the window without the effect
    }
}
