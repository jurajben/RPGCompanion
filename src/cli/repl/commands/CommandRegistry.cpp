#include "CommandRegistry.hpp"

void CommandRegistry::add(std::unique_ptr<ICommand> cmd) {
    map_[cmd->name()] = std::move(cmd);
}
ICommand* CommandRegistry::find(const std::string& name) const {
    auto it = map_.find(name);
    return it == map_.end() ? nullptr : it->second.get();
}
std::vector<const ICommand*> CommandRegistry::all() const {
    std::vector<const ICommand*> v;
    v.reserve(map_.size());
    for (auto& [k, ptr] : map_) v.push_back(ptr.get());
    return v;
}
