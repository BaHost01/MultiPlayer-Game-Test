// NotificationService.cpp
#include "NotificationService.hpp"
#include <iostream>

void NotificationService::Notify(const std::string& title, const std::string& message) {
    std::cout << "[Notification] " << title << ": " << message << std::endl;
}
