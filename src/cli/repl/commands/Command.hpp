#pragma once
#include <string>
#include <vector>

struct CommandContext {
};

class ICommand {
   public:
    virtual ~ICommand() = default;
    virtual std::string name() const = 0;
    virtual std::string summary() const = 0;
    virtual std::string usage() const = 0;
    virtual int run(CommandContext& ctx,
                    const std::vector<std::string>& args) = 0;
};
