// ChatService.cpp
#include "ChatService.hpp"
#include <iostream>

void ChatService::SendMessage(const std::string& sender, const std::string& msg) {
    m_history.push_back({sender, msg});
    std::cout << "[Chat] " << sender << ": " << msg << std::endl;
}
