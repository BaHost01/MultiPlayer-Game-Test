// NetworkHandle.cpp
#include "NetworkHandle.hpp"
#include <curl/curl.h>
#include <nlohmann/json.hpp>   // nlohmann/json single-header

using json = nlohmann::json;

const std::string NetworkHandle::BASE_URL = "https://multiplayer-weld-nu.vercel.app";

// libcurl write callback
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string NetworkHandle::Post(const std::string& url, const std::string& body) {
    CURL* curl = curl_easy_init();
    std::string response;
    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL,            url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS,     body.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER,     headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,      &response);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return response;
}

void NetworkHandle::Connect(ResponseCallback cb) {
    std::string res = Post(BASE_URL + "/", "{}");
    cb(200, res);
}

void NetworkHandle::PlayerPacket(const PlayerPacketData& data, ResponseCallback cb) {
    json body;
    body["user"]   = data.user;
    body["vector"] = { data.x, data.y, data.z };
    std::string res = Post(BASE_URL + "/Packet", body.dump());
    cb(200, res);
}

void NetworkHandle::TriggerBan(const std::string& user, ResponseCallback cb) {
    json body;
    body["user"] = user;
    std::string res = Post(BASE_URL + "/Ban", body.dump());
    cb(200, res);
}
