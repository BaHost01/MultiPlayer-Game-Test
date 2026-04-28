// ServerScriptService.cpp
#include "ServerScriptService.hpp"
#include <iostream>

void ServerScriptService::RegisterScript(const std::string& name, ScriptFn fn) {
    m_scripts[name] = fn;
}

void ServerScriptService::RunScript(const std::string& name) {
    auto it = m_scripts.find(name);
    if (it != m_scripts.end()) {
        it->second();
    } else {
        std::cerr << "Script not found: " << name << std::endl;
    }
}
