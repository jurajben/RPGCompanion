#pragma once
#include <vector>
#include "data/models/Spell.hpp"
#include <sqlite3.h>

class SpellRepository {
public:
    explicit SpellRepository(sqlite3* db) : db_(db) {}

    std::vector<Spell> loadAll() const;
    std::vector<Spell> loadBySchool(SpellSchool school) const;

private:
    sqlite3* db_;
};
