#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// Carga la imagen del mapa en ventana
bool loadMap(sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("MapaProyecto.jpg")) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return false;
    }

    sprite.setTexture(texture);
    return true;
}

// Carga la fuente de texto 
bool loadFont(sf::Font& font) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
        return false;
    }

    return true;
}
// Carga una extension(fondo) en la parte derecha
void extension(sf::RectangleShape& background, sf::RectangleShape& separatorLine) {
    // Establece un fondo al menu de botones
    background.setPosition(700, 0);
    background.setFillColor(sf::Color(178, 228, 237));

    // Linea que separa el mapa del menu de botones
    separatorLine.setSize(sf::Vector2f(5, 700));
    separatorLine.setPosition(700, 0);
    separatorLine.setFillColor(sf::Color::Black);
}