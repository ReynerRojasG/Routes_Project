#pragma once
#include "Button.h"
// Clase para manejar botones de color
class ColorButton : public Button {
private:
    sf::Color color; // Color asociado al boton

public:
    ColorButton() {} // Constructor predeterminado
    ColorButton(const std::string& buttonText, const sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Color& hoverColor, const sf::Color& color)
        : Button(buttonText, font, position, size, fillColor, hoverColor), color(color) {}

    // Obtener el color asociado al boton
    sf::Color getColor() const {
        return color;
    }

    // Determina si el boton es presionado
    bool isPressed(const sf::RenderWindow& window) const {
        return isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
};

