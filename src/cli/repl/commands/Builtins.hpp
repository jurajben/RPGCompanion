#pragma once
#include <string>

#include "Command.hpp"
#include "CommandRegistry.hpp"

class HelpCommand : public ICommand {
   public:
    explicit HelpCommand(const CommandRegistry& reg) : reg_(reg) {}
    std::string name() const override { return "help"; }
    std::string summary() const override { return "Show available commands."; }
    std::string usage() const override { return "help [command]"; }
    int run(CommandContext&, const std::vector<std::string>& args) override;

   private:
    const CommandRegistry& reg_;
};
