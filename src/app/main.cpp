#include <sqlite3.h>
#include <iostream>

#include <iostream>
#include <sqlite3.h>
#include "data/repositories/SpellRepository.hpp"
#include "data/services/SpellService.hpp"
#include "cli/repl/Repl.hpp"
#include "cli/repl/commands/CommandRegistry.hpp"
#include "cli/repl/commands/Builtins.hpp"
#include "cli/repl/commands/ListSpells.hpp"

int main(int argc, char** argv) {
    sqlite3* db = nullptr;
    if (sqlite3_open("dnd_data.db", &db)) {
        std::cerr << "Unable to open database!\n";
        return 1;
    }

    SpellRepository repo(db);
    SpellService service(repo);

    SpellContext ctx(service);
    CommandRegistry reg;
    reg.add(std::make_unique<HelpCommand>(reg));
    reg.add(std::make_unique<ListCommand>());

    Repl repl(reg, ctx, "dnd> ");
    int rc = repl.run();

    sqlite3_close(db);
    return rc;
}

