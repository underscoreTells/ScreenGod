#include "../headers/command_manager.h"

void CommandManager::executeCommand(Command *command) {
    command->execute();
    commandStack.push(command);
}

void CommandManager::undo() {
    if (!commandStack.empty()) {
        Command *command = commandStack.top();
        command->undo();
        commandStack.pop();
        delete command;
    }
}
