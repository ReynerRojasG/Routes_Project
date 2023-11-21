#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "List.h"
#include "CoordenatesFileManager.h"

class Button {
private:
    sf::Color defaultFillColor; // Color del boton 
    sf::Color hoverFillColor; // Color al que cambia si es presionado
    bool flag = false;
    bool deleteNextVertex = false;
    bool showText = false;
public:
    sf::RectangleShape shape;
    sf::Text text;
    Button() {} // Constructor por defecto
    Button(const std::string& buttonText, const sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& defaultColor, const sf::Color& hoverColor); // Comstructor de la clase Button

    void draw(sf::RenderWindow& window); // Dibuja en la ventana
    bool isMouseOver(const sf::RenderWindow& window) const; // Fijar limite de botones
    void update(const sf::RenderWindow& window, bool& addRoutesMode, const List<sf::Vector2f>& coordinates, bool& showRoute, sf::Text& infoText); // Actualiza los botones
    bool shouldDeleteNextVertex() const; // Verifica si eliminar el proximo vertice
    bool isTextVisible() const; // Determina si el texto es visible
    void resetDeletionState(); // Permite que se eliminen las lineas cada que sea presionado
};