#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "data/models/Spell.hpp"
#include "data/models/SpellSchool.hpp"

inline std::string truncate(const std::string& str, std::size_t maxLen) {
    if (str.size() <= maxLen) return str;
    return str.substr(0, maxLen - 3) + "...";
}

inline void printSpellsTable(const std::vector<Spell>& spells) {
    std::cout << "LVL | SCHOOL         | NAME                 | CAST TIME  | "
                 "RANGE    | COMPONENTS\n";
    std::cout << "--- | -------------- | -------------------- | ---------- | "
                 "-------- | ----------\n";
    for (const auto& s : spells) {
        std::cout.width(2);
        std::cout << std::right << s.level << "  | ";
        std::cout.width(14);
        std::cout << std::left << to_string(s.school) << " | ";
        std::cout.width(20);
        std::cout << truncate(s.name, 20) << " | ";
        std::cout.width(10);
        std::cout << truncate(s.cast_time, 10) << " | ";
        std::cout.width(8);
        std::cout << s.range << " | ";
        std::cout.width(10);
        std::cout << s.components << "\n";
    }
}
