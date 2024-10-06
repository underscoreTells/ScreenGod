#ifndef COMMAND
#define COMMAND

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif // COMMAND