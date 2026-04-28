// ServerModel.cpp
#include "ServerModel.hpp"
#include "ServerStorage.hpp"
#include "ServerScriptService.hpp"
#include "NetworkHandle.hpp"

ServerModel* ServerModel::s_instance = nullptr;

ServerModel* ServerModel::Get() {
    if (!s_instance) s_instance = new ServerModel();
    return s_instance;
}

void ServerModel::Init() {
    serverStorage       = std::make_shared<ServerStorage>();
    serverScriptService = std::make_shared<ServerScriptService>();
    handle              = std::make_shared<NetworkHandle>();
}
