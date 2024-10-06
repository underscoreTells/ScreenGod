#ifndef EFFECT_H
#define EFFECT_H

class Effect {
public:
    virtual ~Effect() {}
    virtual void apply() = 0;
    virtual void remove() = 0;
};

#endif // EFFECT_H