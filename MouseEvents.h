#pragma once
#include <SFML/Graphics.hpp>
#include "List.h"
#include "Node.h"

// Funcion para manejar eventos del mouse, especificamente relacionados con la adicion y finalizacion de rutas
void handleMouseEvents(sf::Event event, bool& addRoutesMode, List<sf::Vector2f>& listCoordenates, sf::VertexArray& lines, sf::Color lineColor, bool showLines, bool& showRoute) {
    // Si esta en modo de agregar rutas y se presiona el boton izquierdo del mouse
    if (addRoutesMode && event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Obtiene la posicion del mouse
            sf::Vector2f position(event.mouseButton.x, event.mouseButton.y);
            
             // Si la posicion esta dentro del area de dibujo (0 a 700 en x y en y)
            if (position.x >= 0 && position.x <= 700 && position.y >= 0 && position.y <= 700) {
                // Inserta la posicion en la lista de coordenadas
                listCoordenates.Insert(position);
               
                // Añade la posiciin a las líneas
                lines.append(position);
                lines[lines.getVertexCount() - 1].color = lineColor; // Asigna el color de la linea
            }
        }
    }
    // Si no esta en modo de agregar rutas y se presiona el botin izquierdo del ratin
    if (!addRoutesMode && event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Se deja de graficar lineas
            showLines = false;
        }
    }
}
