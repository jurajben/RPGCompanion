#pragma once
#include "cli/repl/commands/Command.hpp"
#include "data/services/SpellService.hpp"

struct SpellContext : CommandContext {
    SpellService& service;
    explicit SpellContext(SpellService& s) : service(s) {}
};

class ListCommand : public ICommand {
public:
    std::string name() const override { return "listSpells"; }
    std::string summary() const override { return "List all available spells"; }
    std::string usage() const override { return "listSpells"; }
    int run(CommandContext& base, const std::vector<std::string>& args) override;
};
