#ifndef VIDEO_EFFECT_H
#define VIDEO_EFFECT_H

#include "effect.h"

class VideoEffect : public Effect {
public:
    void apply() override;
    void remove() override;
};

#endif // VIDEO_EFFECT_H
