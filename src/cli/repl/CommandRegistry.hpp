#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Command.hpp"

class CommandRegistry {
   public:
    void add(std::unique_ptr<ICommand> cmd);
    ICommand* find(const std::string& name) const;
    std::vector<const ICommand*> all() const;

   private:
    std::unordered_map<std::string, std::unique_ptr<ICommand>> map_;
};
