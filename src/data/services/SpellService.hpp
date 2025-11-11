#pragma once

#include <vector>

#include "data/models/Spell.hpp"
#include "data/repositories/SpellRepository.hpp"

class SpellService {
   public:
    explicit SpellService(SpellRepository& repo);

    std::vector<Spell> listAll() const;
    
   private:
    SpellRepository& repo_;
};
