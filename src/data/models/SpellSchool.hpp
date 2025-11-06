#pragma once
#include <array>
#include <string>

enum class SpellSchool : int {
    Abjuration = 0,
    Conjuration,
    Divination,
    Enchantment,
    Evocation,
    Illusion,
    Necromancy,
    Transmutation
};

inline const std::array<const char*, 8> kSpellSchoolNames = {
    "Abjuration", "Conjuration", "Divination", "Enchantment",
    "Evocation",  "Illusion",    "Necromancy", "Transmutation"};

inline std::string to_string(SpellSchool s) {
    int i = static_cast<int>(s);
    return (i >= 0 && i < (int)kSpellSchoolNames.size()) ? kSpellSchoolNames[i]
                                                         : "Unknown";
}

inline SpellSchool spellSchoolFromInt(int v) {
    if (v < 0 || v >= (int)kSpellSchoolNames.size())
        return SpellSchool::Abjuration;
    return static_cast<SpellSchool>(v);
}
