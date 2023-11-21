#pragma once
#include <SFML/Graphics.hpp>
#include "ButtonManager.h"

// Funcion para dibujar los elementos en la ventana
void drawElements(sf::RenderWindow& window, sf::Text& infoText, sf::VertexArray& lines, bool showText, bool showLines, bool showRoute,
    sf::RectangleShape& background, sf::RectangleShape& separatorLine,
    sf::RectangleShape& headerBackground, sf::Text& headerText,
    Button& addRouteButton, Button& endRouteButton, Button& saveRouteButton,
    Button& hideRouteButton, Button& showRouteButton, Button& deleteRouteButton,
    ColorButton& colorButtonRed, ColorButton& colorButtonBlue, ColorButton& colorButtonYellow,
    ColorButton& colorButtonMagenta, ColorButton& colorButtonCyan, ColorButton& colorButtonGreen) {

    // Muestra el texto de guardado
    if (showText) {
        window.draw(infoText);
    }

    // Dibuja la ruta
    if (showLines && showRoute) {
        window.draw(lines);
    }

    // Dibuja la extensión de la parte derecha (el fondo de los botones)
    window.draw(background);
    window.draw(separatorLine);

    // Dibuja el fondo
    window.draw(headerBackground);
    // Dibuja el texto
    window.draw(headerText);

    // Dibuja los botones
    addRouteButton.draw(window);
    endRouteButton.draw(window);
    saveRouteButton.draw(window);
    hideRouteButton.draw(window);
    showRouteButton.draw(window);
    deleteRouteButton.draw(window);
    // Dibuja los botones de colores
    colorButtonRed.draw(window);
    colorButtonBlue.draw(window);
    colorButtonYellow.draw(window);
    colorButtonMagenta.draw(window);
    colorButtonCyan.draw(window);
    colorButtonGreen.draw(window);
}