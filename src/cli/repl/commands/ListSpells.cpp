#include "ListSpells.hpp"
#include "cli/Print.hpp"

int ListCommand::run(CommandContext& base, const std::vector<std::string>& args) {
    auto& ctx = static_cast<SpellContext&>(base);

    auto spells = ctx.service.listAll();
    printSpellsTable(spells);
    return 0;
}
