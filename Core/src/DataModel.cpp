// DataModel.cpp
#include "DataModel.hpp"
#include "Game.hpp"
#include "Players.hpp"
#include "ExampleService.hpp"
#include "ChatService.hpp"
#include "NotificationService.hpp"
#include "ShooterService.hpp"
#include "MapService.hpp"

DataModel* DataModel::s_instance = nullptr;

DataModel* DataModel::Get() {
    if (!s_instance) s_instance = new DataModel();
    return s_instance;
}

void DataModel::Init() {
    game                = std::make_shared<Game>();
    players             = std::make_shared<Players>();
    exampleService      = std::make_shared<ExampleService>();
    chatService         = std::make_shared<ChatService>();
    notificationService = std::make_shared<NotificationService>();
    shooterService      = std::make_shared<ShooterService>();
    mapService          = std::make_shared<MapService>();
}

void DataModel::Destroy() {
    s_instance = nullptr;
}
