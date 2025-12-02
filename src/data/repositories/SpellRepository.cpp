#include "SpellRepository.hpp"

#include <stdexcept>

static void check(int rc) {
    if (rc != SQLITE_OK && rc != SQLITE_ROW && rc != SQLITE_DONE) {
        throw std::runtime_error("SQLite error");
    }
}

static Spell fillSpell(sqlite3_stmt* st) {
    Spell s;
    s.id = sqlite3_column_int64(st, 0);
    s.name = reinterpret_cast<const char*>(sqlite3_column_text(st, 1));
    s.level = sqlite3_column_int(st, 2);
    s.school = spellSchoolFromInt(sqlite3_column_int(st, 3));
    s.cast_time = reinterpret_cast<const char*>(sqlite3_column_text(st, 4));
    s.range = reinterpret_cast<const char*>(sqlite3_column_text(st, 5));
    s.components = reinterpret_cast<const char*>(sqlite3_column_text(st, 6));
    s.duration = reinterpret_cast<const char*>(sqlite3_column_text(st, 7));
    s.description = reinterpret_cast<const char*>(sqlite3_column_text(st, 8));
    return s;
}

std::vector<Spell> SpellRepository::loadAll() const {
    const char* sql =
        "SELECT id, name, level, school, cast_time, range, components, duration, "
        "IFNULL(description,'') "
        "FROM Spells ORDER BY level, name;";
    sqlite3_stmt* st = nullptr;
    check(sqlite3_prepare_v2(db_, sql, -1, &st, nullptr));

    std::vector<Spell> out;
    while (sqlite3_step(st) == SQLITE_ROW) {
        out.emplace_back(fillSpell(st));
    }
    sqlite3_finalize(st);
    return out;
}

std::vector<Spell> SpellRepository::loadBySchool(SpellSchool school) const {
    const char* sql =
        "SELECT id, name, level, school, cast_time, range, components, duration, "
        "IFNULL(description,'') "
        "FROM Spells WHERE school = ? ORDER BY level, name;";
    sqlite3_stmt* st = nullptr;
    check(sqlite3_prepare_v2(db_, sql, -1, &st, nullptr));
    check(sqlite3_bind_int(st, 1, static_cast<int>(school)));

    std::vector<Spell> out;
    while (sqlite3_step(st) == SQLITE_ROW) {
        out.emplace_back(fillSpell(st));
    }
    sqlite3_finalize(st);
    return out;
}
