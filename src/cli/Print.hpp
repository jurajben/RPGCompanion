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

inline void printLine() {
    std::cout << "-------------------- | --- | -------------- | ---------- | "
                 "-------- | ---------- | ------------- \n";
}

inline void printSpellsTable(const std::vector<Spell>& spells) {
    int prev_lvl = spells[0].level;
    std::cout << "NAME                 | LVL | SCHOOL         | CAST TIME  | "
                 "RANGE    | COMPONENTS | DURATION      \n";
    printLine();
    for (const auto& s : spells) {
        if (s.level > prev_lvl) {
            printLine();
        }
        std::cout.width(20);
        std::cout << std::left << truncate(s.name, 20) << " | ";
        std::cout.width(2);
        std::cout << std::right << s.level << "  | ";
        std::cout.width(14);
        std::cout << std::left << to_string(s.school) << " | ";
        std::cout.width(10);
        std::cout << truncate(s.cast_time, 10) << " | ";
        std::cout.width(8);
        std::cout << s.range << " | ";
        std::cout.width(10);
        std::cout << s.components << " | ";
        std::cout.width(13);
        std::cout << s.duration << "\n";
        prev_lvl = s.level;
    }
}
