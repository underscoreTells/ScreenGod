#ifndef APPLY_EFFECT_COMMAND
#define APPLY_EFFECT_COMMAND

#include "command.h"
#include "effect.h"

class ApplyEffectCommand : public Command {
private:
    Effect *effect;

public:
    ApplyEffectCommand(Effect *e) : effect(e) {}

    void execute() override;

    void undo() override;
};

#endif // SHADER_EFFECT_WIDGET_H