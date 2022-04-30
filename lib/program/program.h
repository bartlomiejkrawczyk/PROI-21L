#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "../command/command.h"
#include "../memory/memory.h"
#include "../stack_machine/stack_machine.h"

class Value;

class Program {
    std::vector<std::unique_ptr<Command>> instructions;
    size_t instruction = 0;

public:
    Memory memory;
    StackMachine stack;

    void addInstruction(std::unique_ptr<Command> instruction);

    void step();

    void run();

private:
    void call(const Command& command);

public:
    friend std::ostream& operator<<(std::ostream& os, const Program& program);
};