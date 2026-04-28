// DataModel.hpp
#pragma once
#include <memory>
#include <string>
#include <unordered_map>

class Game;
class Players;
class ExampleService;
class ChatService;
class NotificationService;
class ShooterService;
class MapService;

class DataModel {
public:
    static DataModel* Get();          // Singleton accessor
    void Init();
    void Destroy();

    std::shared_ptr<Game>                game;
    std::shared_ptr<Players>             players;
    std::shared_ptr<ExampleService>      exampleService;
    std::shared_ptr<ChatService>         chatService;
    std::shared_ptr<NotificationService> notificationService;
    std::shared_ptr<ShooterService>      shooterService;
    std::shared_ptr<MapService>          mapService;

private:
    static DataModel* s_instance;
    DataModel() = default;
};
