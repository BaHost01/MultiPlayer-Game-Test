// NetworkHandle.hpp
#pragma once
#include <string>
#include <functional>

struct PlayerPacketData {
    std::string user;
    float x, y, z;
    // extend with any extra fields
};

using ResponseCallback = std::function<void(int httpCode, const std::string& body)>;

class NetworkHandle {
public:
    static const std::string BASE_URL; // "https://multiplayer-weld-nu.vercel.app"

    // Connect — POST /  (handshake)
    void Connect(ResponseCallback cb);

    // PlayerPacket — POST /Packet  { user, vector, etc. }
    void PlayerPacket(const PlayerPacketData& data, ResponseCallback cb);

    // TriggerBan — POST /Ban  { user }
    void TriggerBan(const std::string& user, ResponseCallback cb);

private:
    std::string Post(const std::string& url, const std::string& jsonBody);
    std::string Get(const std::string& url);
};
