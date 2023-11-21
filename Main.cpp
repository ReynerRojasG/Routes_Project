#include <SFML/Graphics.hpp>
#include <iostream>
#include "List.h"
#include "Node.h"
#include "Button.h"
#include "CoordenatesFileManager.h"  
#include "ColorButton.h"
#include "ButtonManager.h"
#include "Map.h"
#include "Text.h"
#include "MouseEvents.h"
#include "Draw.h"

int main() {
    // Crea una ventana SFML
    sf::RenderWindow window(sf::VideoMode(950, 700), "Graficar Rutas");
    // Crea textura y sprite para el mapa
    sf::Texture texture;
    sf::Sprite sprite;
    // Crear un conjunto de vertices para representar las lineas de la ruta
    sf::VertexArray lines(sf::LinesStrip);
    // Color de las lineas
    sf::Color lineColor;
    // Fuente para texto
    sf::Font font;
    // Fondo del menu de botones
    sf::RectangleShape background(sf::Vector2f(250, 700));
    // Linea separadora
    sf::RectangleShape separatorLine;
    // Variables de control
    bool showLines = true; 
    bool showRoute = true;
    bool addRoutesMode = false;
    bool showText = false;
    // Texto de guardado
    sf::Text infoText;
    // Fondo para texto "COLORES"
    sf::RectangleShape headerBackground;
    // Texto para colores
    sf::Text headerText;

    // Botones
    Button addRouteButton;
    Button endRouteButton;
    Button saveRouteButton;
    Button hideRouteButton;
    Button showRouteButton;
    Button deleteRouteButton;

    // Botones de colores
    ColorButton colorButtonRed;
    ColorButton colorButtonBlue;
    ColorButton colorButtonYellow;
    ColorButton colorButtonMagenta;
    ColorButton colorButtonCyan;
    ColorButton colorButtonGreen;

    // Se crea un buttonManager
    ButtonManager buttonManager;

    // Carga el mapa
    if (!loadMap(texture, sprite) || !loadFont(font)) {
        return 1;
    }

    // Se crea una lista para almacenar coordenadas de la ruta
    List<sf::Vector2f> listCoordenates;

    // Configuracion del texto de guardado
    configureTextSavedText(infoText, font);

    // Configuracion del texto para colores
    configureTextColors(headerText, headerBackground, font);

    // Llama a la funcion para inicializar los botones
    buttonManager.initializeButtons(addRouteButton, endRouteButton, saveRouteButton, hideRouteButton, showRouteButton, deleteRouteButton, colorButtonRed, colorButtonBlue, colorButtonYellow, colorButtonMagenta, colorButtonCyan, colorButtonGreen, font);

    // Llama a la funcion para dibujar el fondo del menu de botones 
    extension(background, separatorLine);

    // Bucle principal 
    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Manejo de eventos del mouse
            handleMouseEvents(event, addRoutesMode, listCoordenates, lines, lineColor, showLines, showRoute);

            // Verifica si se debe eliminar el proximo vertice al hacer clic en el boton "Eliminar Ruta"
            if (deleteRouteButton.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                listCoordenates.DeleteLast(lines);

                // Reinicia el estado de eliminacion en el boton
                deleteRouteButton.resetDeletionState();
            }
        }

        // Limpia la ventana
        window.clear();
        // Dibuja el mapa
        window.draw(sprite);

        // Llamada a lad funciones de actualizacion de botones
        buttonManager.updateButtons(window, addRouteButton, endRouteButton, saveRouteButton, hideRouteButton, showRouteButton, deleteRouteButton, colorButtonRed, colorButtonBlue, colorButtonYellow, colorButtonMagenta, colorButtonCyan, colorButtonGreen, addRoutesMode, listCoordenates, showLines, showRoute, infoText);
        
        // Actualiza los colores de las lineas segun los botones de colores
        buttonManager.updateColorButtons(window, lineColor, colorButtonRed, colorButtonBlue, colorButtonYellow, colorButtonMagenta, colorButtonCyan, colorButtonGreen);

        // Maneja los botones principales
        buttonManager.handleButtons(window, endRouteButton, saveRouteButton, hideRouteButton, showRouteButton, addRoutesMode, showText, listCoordenates, showLines, infoText);
       
        // Dibuja todos los elementos en la ventana
        drawElements(window, infoText, lines, showText, showLines, showRoute, background, separatorLine, headerBackground, headerText,
            addRouteButton, endRouteButton, saveRouteButton,
            hideRouteButton, showRouteButton, deleteRouteButton,
            colorButtonRed, colorButtonBlue, colorButtonYellow,
            colorButtonMagenta, colorButtonCyan, colorButtonGreen);
        
        // Muestra la ventana
        window.display();
    }
    return 0;
}