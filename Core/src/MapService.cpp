// MapService.cpp
#include "MapService.hpp"
#include <iostream>

void MapService::LoadMap(const std::string& mapName) {
    m_objects.clear();
    std::cout << "Loading map: " << mapName << std::endl;
    
    // Add some default objects for a basic map
    AddObject({"Ground", 0, -1, 0, 100, 1, 100});
    AddObject({"Wall_North", 0, 5, 50, 100, 10, 1});
    AddObject({"Wall_South", 0, 5, -50, 100, 10, 1});
}

void MapService::AddObject(const MapObject& obj) {
    m_objects.push_back(obj);
    std::cout << "Added object: " << obj.name << " at (" << obj.x << ", " << obj.y << ", " << obj.z << ")" << std::endl;
}
