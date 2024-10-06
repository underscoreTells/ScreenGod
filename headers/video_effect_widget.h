#ifndef VIDEO_EFFECT_WIDGET_H
#define VIDEO_EFFECT_WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

class VideoEffectWidget : public QWidget {
private:
    Q_OBJECT
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;

public:
    VideoEffectWidget(QWidget *parent = nullptr);
};

#endif // VIDEO_EFFECT_WIDGET_H
