// main.cpp
#include "DataModel.hpp"
#include "ServerModel.hpp"
#include "NetworkHandle.hpp"
#include "ShooterService.hpp"
#include "MapService.hpp"
#include <cstdio>

void AppInit() {
    // Boot DataModel
    DataModel* DM = DataModel::Get();
    DM->Init();

    // Boot ServerModel
    ServerModel* SM = ServerModel::Get();
    SM->Init();

    // Game Logic
    DM->shooterService->StartGame();
    DM->mapService->LoadMap("Main_Level");

    // Connect to multiplayer backend
    SM->handle->Connect([](int code, const std::string& body) {
        printf("[Connect] %d — %s\n", code, body.c_str());
    });

    // Send player packet
    PlayerPacketData packet { "Player1", 10.f, 0.f, 5.f };
    SM->handle->PlayerPacket(packet, [](int code, const std::string& body) {
        printf("[Packet] %d — %s\n", code, body.c_str());
    });

    // Simulate some gameplay
    DM->shooterService->Shoot();
}

int main() {
    AppInit();
    return 0;
}
