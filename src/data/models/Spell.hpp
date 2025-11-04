#pragma once
#include <string>
#include "SpellSchool.hpp"

struct Spell {
    long long id;
    std::string name;
    int level;
    SpellSchool school;
    std::string cast_time;
    std::string range;
    std::string components;
    std::string description;
};

