// ChatService.hpp
#pragma once
#include <string>
#include <vector>

struct ChatMessage {
    std::string sender;
    std::string message;
};

class ChatService {
public:
    void SendMessage(const std::string& sender, const std::string& msg);
    const std::vector<ChatMessage>& GetHistory() const { return m_history; }

private:
    std::vector<ChatMessage> m_history;
};
