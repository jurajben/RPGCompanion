#pragma once
#include <string>

#include "cli/repl/commands/Command.hpp"
#include "cli/repl/commands/CommandRegistry.hpp"

class Repl {
   public:
    Repl(CommandRegistry& reg, CommandContext& ctx,
         std::string prompt = "D&C> ")
        : reg_(reg), ctx_(ctx), prompt_(std::move(prompt)) {}
    int run();

   private:
    CommandRegistry& reg_;
    CommandContext& ctx_;
    std::string prompt_;
    bool handleLine(const std::string& line);
};
