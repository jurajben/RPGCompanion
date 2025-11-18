#include "Repl.hpp"

#include <iostream>

std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> out;
    std::string cur;
    bool inq = false;
    for (char c : s) {
        if (c == '"') {
            inq = !inq;
            continue;
        }
        if (!inq && std::isspace((unsigned char)c)) {
            if (!cur.empty()) {
                out.push_back(cur);
                cur.clear();
            }
        } else
            cur.push_back(c);
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

int Repl::run() {
    std::string line;
    while (true) {
        std::cout << prompt_;
        if (!std::getline(std::cin, line)) {
            std::cout << "\n";
            break;
        }
        if (!handleLine(line)) break;
    }
    return 0;
}

bool Repl::handleLine(const std::string& line) {
    auto tokens = tokenize(line);
    if (tokens.empty()) return true;
    const std::string cmdName = tokens[0];
    std::vector<std::string> args(tokens.begin() + 1, tokens.end());

    if (cmdName == "exit" || cmdName == "quit" || cmdName == "q") return false;

    if (auto* cmd = reg_.find(cmdName)) {
        int rc = cmd->run(ctx_, args);
        if (rc != 0) std::cout << "(error " << rc << ")\n";
    } else {
        std::cout << "Unknown command: " << cmdName << " (try `help`)\n";
    }
    return true;
}
