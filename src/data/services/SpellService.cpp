#include "SpellService.hpp"

SpellService::SpellService(SpellRepository& repo) : repo_(repo) {}

std::vector<Spell> SpellService::listAll() const {
    return repo_.loadAll();
}
