#include "ButtonManager.h"

// Clase para gestionar y manejar el conjunto de botones
void ButtonManager::initializeButtons(Button& addRouteButton, Button& endRouteButton, Button& saveRouteButton, Button& hideRouteButton, Button& showRouteButton, Button& deleteRouteButton, ColorButton& colorButtonRed, ColorButton& colorButtonBlue, ColorButton& colorButtonYellow, ColorButton& colorButtonMagenta, ColorButton& colorButtonCyan, ColorButton& colorButtonGreen, sf::Font& font)
{
    // Inicializa el boton "Agregar Ruta"
    addRouteButton = Button("Agregar Ruta", font, sf::Vector2f(775, 30), sf::Vector2f(100, 50), sf::Color(4, 13, 18), sf::Color(39, 55, 77));
    // Inicializa el boton "Finalizar Ruta"
    endRouteButton = Button("Finalizar Ruta", font, sf::Vector2f(775, 100), sf::Vector2f(100, 50), sf::Color(24, 61, 61), sf::Color(82, 109, 130));
    // Inicializa el boton "Guardar Ruta"
    saveRouteButton = Button("Guardar Ruta", font, sf::Vector2f(775, 170), sf::Vector2f(100, 50), sf::Color(92, 131, 116), sf::Color(157, 178, 191));
    // Inicializa el boton "Ocultar Ruta"
    hideRouteButton = Button("Ocultar Ruta", font, sf::Vector2f(775, 240), sf::Vector2f(100, 50), sf::Color(147, 177, 116), sf::Color(209, 218, 226));
    // Inicializa el boton "Mostrar Ruta"
    showRouteButton = Button("Mostrar Ruta", font, sf::Vector2f(775, 310), sf::Vector2f(100, 50), sf::Color(107, 168, 169), sf::Color(20, 39, 78));
    // Inicializa el boton "Eliminar Ruta"
    deleteRouteButton = Button("Eliminar Ruta", font, sf::Vector2f(775, 380), sf::Vector2f(100, 50), sf::Color(53, 115, 118), sf::Color(57, 72, 103));
    // Inicializa los botones de colores
    colorButtonRed = ColorButton(" ", font, sf::Vector2f(775, 600), sf::Vector2f(30, 30), sf::Color::Red, sf::Color(255, 0, 0, 150), sf::Color::Red);
    colorButtonBlue = ColorButton(" ", font, sf::Vector2f(810, 600), sf::Vector2f(30, 30), sf::Color::Blue, sf::Color(0, 0, 255, 150), sf::Color::Blue);
    colorButtonYellow = ColorButton(" ", font, sf::Vector2f(845, 600), sf::Vector2f(30, 30), sf::Color::Yellow, sf::Color(0, 0, 255, 150), sf::Color::Yellow);
    colorButtonMagenta = ColorButton(" ", font, sf::Vector2f(775, 635), sf::Vector2f(30, 30), sf::Color::Magenta, sf::Color(0, 0, 255, 150), sf::Color::Magenta);
    colorButtonCyan = ColorButton(" ", font, sf::Vector2f(810, 635), sf::Vector2f(30, 30), sf::Color::Cyan, sf::Color(0, 0, 255, 150), sf::Color::Cyan);
    colorButtonGreen = ColorButton(" ", font, sf::Vector2f(845, 635), sf::Vector2f(30, 30), sf::Color::Green, sf::Color(0, 0, 255, 150), sf::Color::Green);
}

void ButtonManager::updateButtons(sf::RenderWindow& window, Button& addRouteButton, Button& endRouteButton, Button& saveRouteButton, Button& hideRouteButton, Button& showRouteButton, Button& deleteRouteButton, ColorButton& colorButtonRed, ColorButton& colorButtonBlue, ColorButton& colorButtonYellow, ColorButton& colorButtonMagenta, ColorButton& colorButtonCyan, ColorButton& colorButtonGreen, bool& addRoutesMode, List<sf::Vector2f>& listCoordenates, bool& showLines, bool& showRoute, sf::Text& infoText)
{
    addRouteButton.update(window, addRoutesMode, listCoordenates, showLines, infoText);
    endRouteButton.update(window, addRoutesMode, listCoordenates, showLines, infoText);
    saveRouteButton.update(window, addRoutesMode, listCoordenates, showLines, infoText);
    hideRouteButton.update(window, addRoutesMode, listCoordenates, showLines, infoText);
    showRouteButton.update(window, addRoutesMode, listCoordenates, showRoute, infoText);
    deleteRouteButton.update(window, addRoutesMode, listCoordenates, showLines, infoText);
}

void ButtonManager::updateColorButtons(const sf::RenderWindow& window, sf::Color& lineColor, const ColorButton& colorButtonRed, const ColorButton& colorButtonBlue, const ColorButton& colorButtonYellow, const ColorButton& colorButtonMagenta, const ColorButton& colorButtonCyan, const ColorButton& colorButtonGreen)
{
    // Casos para que las lineas cambien al color presionado
    if (colorButtonRed.isPressed(window)) {
        lineColor = colorButtonRed.getColor();
    }
    else if (colorButtonBlue.isPressed(window)) {
        lineColor = colorButtonBlue.getColor();
    }
    else if (colorButtonYellow.isPressed(window)) {
        lineColor = colorButtonYellow.getColor();
    }
    else if (colorButtonMagenta.isPressed(window)) {
        lineColor = colorButtonMagenta.getColor();
    }
    else if (colorButtonCyan.isPressed(window)) {
        lineColor = colorButtonCyan.getColor();
    }
    else if (colorButtonGreen.isPressed(window)) {
        lineColor = colorButtonGreen.getColor();
    }
}

void ButtonManager::handleButtons(sf::RenderWindow& window, Button& endRouteButton, Button& saveRouteButton, Button& hideRouteButton, Button& showRouteButton, bool& addRoutesMode, bool& showText, List<sf::Vector2f>& listCoordenates, bool& showLines, sf::Text& infoText)
{
    // Si se presiona "Finalizar Ruta"
    if (endRouteButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        addRoutesMode = false;   // Agregar líneas ahora está desactivado
        showText = false;
    }

    if (saveRouteButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        addRoutesMode = false;   // Agregar líneas ahora está desactivado
        CoordenatesFileManager::SaveCoordinates(listCoordenates, "coordenadas.txt"); // Llama a método GuardarCoordenadas para guardarlas en el archivo  
        showText = true;
    }

    // Si se presiona "Ocultar Ruta", cambia el estado de mostrarLineas
    if (hideRouteButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        showLines = false; // Oculta
        showText = false;
    }

    // Si se presiona "Mostrar Ruta", cambia el estado de mostrarLineas
    if (showRouteButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        showLines = true; // Muestra
        showText = false;
    }
}
