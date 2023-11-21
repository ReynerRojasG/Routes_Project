#include "Button.h"
#include "List.h"
#include "CoordenatesFileManager.h"

// Constructor de la clase Button
Button::Button(const std::string& buttonText, const sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& defaultColor, const sf::Color& hoverColor)
    : defaultFillColor(defaultColor), hoverFillColor(hoverColor), flag(false), deleteNextVertex(false), showText(false) {
    // Configuracion de la forma del boton
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(defaultColor);

    // Configuracion del texto del boton
    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(14.5);
    text.setPosition(position.x + 10, position.y + 10);
    text.setFillColor(sf::Color::White);
}
// Metodo para dibujar el boton en la ventana
void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}
// Metodo para verificar si el mouse se encuentra sobre el boton
bool Button::isMouseOver(const sf::RenderWindow& window) const {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); // Obtiene la posicion actual del mouse
    sf::FloatRect bounds = shape.getGlobalBounds(); // Obtiene los limites globales del boton en relacion con la ventana
    return bounds.contains(mousePosition.x, mousePosition.y); // Verifica si las coordenadas del raton estan dentro de los limites globales del boton
}

// Metodo para actualizar el estado del boton
void Button::update(const sf::RenderWindow& window, bool& addRoutesMode, const List<sf::Vector2f>& coordinates, bool& showRoute, sf::Text& infoText) {
    static CoordenatesFileManager coordenatesFileManager; // Crear una instancia

    // Verificar si el boton está siendo presionado
    if (isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Realiza acciones específicas para cada boton solo si flag es falso
        if (!flag) {
            flag = true;
            shape.setFillColor(hoverFillColor);

            if (text.getString() == "Agregar Ruta") {
                // Habilita el modo de agregar rutas
                addRoutesMode = true;
                showText = false;
            }
            else if (text.getString() == "Finalizar Ruta") {
                // Deshabilita el modo de agregar rutas
                addRoutesMode = false;
                showText = false;
            }
            else if (text.getString() == "Guardar Ruta") {
                CoordenatesFileManager::SaveCoordinates(coordinates, "coordenadas.txt");
                infoText.setString("Ruta guardada en coordenadas.txt");
                showText = true;  // Establece showText como true para mostrar el texto         
            }
            else if (text.getString() == "Mostrar Ruta") {
                // Cambia el estado de mostrarRutas
                showRoute = !showRoute;
                showText = false;
            }
            else if (text.getString() == "Eliminar Ruta" && isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                deleteNextVertex = true;
                showText = false;
            }

            // Restablecer flag a false
            flag = false;
        }
    }
    else if (flag) {
        shape.setFillColor(hoverFillColor);
    }
    else {
        shape.setFillColor(defaultFillColor);
    }

}

// Metodo para verificar si se debe eliminar el proximo vertice
bool Button::shouldDeleteNextVertex() const {
    return deleteNextVertex;
}
// Metodo para verificar si el texto del boton debe ser visible
bool Button::isTextVisible() const {
    return showText;
}

// Metodo para que se pueda realizar la proxima eliminacion cuando el boton sea presionado nuevamente
void Button::resetDeletionState() {
    deleteNextVertex = false;
}

