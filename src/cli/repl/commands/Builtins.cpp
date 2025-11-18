#include "Builtins.hpp"
#include <iostream>

int HelpCommand::run(CommandContext&, const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cout << "Commands:\n";
        for (auto* c : reg_.all())
            std::cout << "  " << c->name() << "  - " << c->summary() << "\n";
        std::cout << "  exit / quit - Exit the REPL\n";
        return 0;
    }

    const std::string& cmdName = args[0];
    if (auto* cmd = reg_.find(cmdName)) {
        std::cout << cmd->usage() << "\n";
        return 0;
    }

    std::cout << "No such command: " << args[0] << "\n";
    return 1;
}

