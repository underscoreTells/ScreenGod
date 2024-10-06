#include "../headers/apply_effect_command.h"

ApplyEffectCommand::ApplyEffectCommand(Effect *e) : effect(e) {}

void ApplyEffectCommand::execute() {
    effect->apply();
}

void ApplyEffectCommand::undo() {
    effect->remove();
}
