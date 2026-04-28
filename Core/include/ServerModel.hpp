// ServerModel.hpp
#pragma once
#include <memory>

class ServerStorage;
class ServerScriptService;
class NetworkHandle;

class ServerModel {
public:
    static ServerModel* Get();
    void Init();

    std::shared_ptr<ServerStorage>      serverStorage;
    std::shared_ptr<ServerScriptService> serverScriptService;
    std::shared_ptr<NetworkHandle>      handle;

private:
    static ServerModel* s_instance;
    ServerModel() = default;
};
