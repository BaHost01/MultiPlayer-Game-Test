// ServerScriptService.hpp
#pragma once
#include <functional>
#include <unordered_map>
#include <string>

using ScriptFn = std::function<void()>;

class ServerScriptService {
public:
    void RegisterScript(const std::string& name, ScriptFn fn);
    void RunScript(const std::string& name);

private:
    std::unordered_map<std::string, ScriptFn> m_scripts;
};
