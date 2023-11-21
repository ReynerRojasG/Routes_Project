#pragma once
#include <SFML/Graphics.hpp>

// Configura el fondo, tamaño, color y posicion del texto al "Guardar Ruta" 
void configureTextSavedText(sf::Text& infoText, sf::Font& font) {
    infoText.setFont(font);
    infoText.setCharacterSize(18);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(10, 10); 
}
    // Configuracion del fondo del texto para colores
void configureTextColors(sf::Text& headerText, sf::RectangleShape& headerBackground, sf::Font& font) {
    headerBackground.setSize(sf::Vector2f(120, 130)); // Ajusta el tamaño del fondo
    headerBackground.setPosition(765, 550);
    headerBackground.setFillColor(sf::Color::Black);

    // Configuración del texto para colores
    headerText.setFont(font);
    headerText.setString("COLORES");
    headerText.setCharacterSize(14);
    headerText.setFillColor(sf::Color::White);
    headerText.setPosition(790, 560); 
}