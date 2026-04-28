// MapService.hpp
#pragma once
#include <vector>
#include <string>

struct MapObject {
    std::string name;
    float x, y, z;
    float sx, sy, sz; // scale
};

class MapService {
public:
    void LoadMap(const std::string& mapName);
    void AddObject(const MapObject& obj);
    const std::vector<MapObject>& GetObjects() const { return m_objects; }

private:
    std::vector<MapObject> m_objects;
};
