#ifndef OVERLAY_WINDOW_H
#define OVERLAY_WINDOW_H

#include <QOpenGLWidget>
#include <QTimer>
#include "shader_effect.h"
#include "video_effect.h"
#include "command_manager.h"
#include "apply_effect_command.h"

class OverlayWindow : public QOpenGLWidget {
private:
    Q_OBJECT
    ShaderEffect *shaderEffect;
    VideoEffect *videoEffect;
    CommandManager *commandManager;
    Effect *currentEffect;  // Pointer to the current effect
    QTimer effectTimer;

public:
    OverlayWindow();
    void triggerRandomEffect(int durationMs);

protected:
    void initializeGL() override;
    void paintGL() override;

private slots:
    void revertToNormal();
};

#endif // OVERLAY_WINDOW_H
