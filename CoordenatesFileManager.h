#pragma once
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "List.h"
class CoordenatesFileManager
{
public:
    CoordenatesFileManager() {}
    static void SaveCoordinates(const List<sf::Vector2f>& coordinates, const std::string& nameFile);
};


