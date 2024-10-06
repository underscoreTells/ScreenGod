#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include "../headers/command.h"
#include <stack>

using namespace std;

class CommandManager {
private:
    stack<Command*> commandStack;

public:
    void executeCommand(Command *command);

    void undo();
};

#endif // COMMAND_MANAGER