#include "../headers/video_effect_widget.h"

VideoEffectWidget::VideoEffectWidget(QWidget *parent) : QWidget(parent) {
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->setMedia(QUrl::fromLocalFile("path/to/your/video.mp4"));
    mediaPlayer->play();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    setLayout(layout);
}
