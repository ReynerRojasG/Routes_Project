#pragma once
#include "Button.h"  
#include "ColorButton.h"  
#include "List.h"  
#include "CoordenatesFileManager.h"  
#include <SFML/Graphics.hpp>

class ButtonManager {
public:
	// Inicializa botones con posiciones predeterminadas, colores y tamaños
	void initializeButtons(Button& agregarRutaButton, Button& finalizarRutaButton, Button& guardarRutaButton, Button& ocultarRutaButton, Button& mostrarRutaButton, Button& eliminarRutaButton, ColorButton& colorButtonRed, ColorButton& colorButtonBlue, ColorButton& colorButtonYellow, ColorButton& colorButtonMagenta, ColorButton& colorButtonCyan, ColorButton& colorButtonGreen, sf::Font& font);
	
	// Actualiza el estado de los botones según la entrada del mouse y realiza acciones especificas
	void updateButtons(sf::RenderWindow& window, Button& agregarRutaButton, Button& finalizarRutaButton, Button& guardarRutaButton, Button& ocultarRutaButton, Button& mostrarRutaButton, Button& eliminarRutaButton, ColorButton& colorButtonRed, ColorButton& colorButtonBlue, ColorButton& colorButtonYellow, ColorButton& colorButtonMagenta, ColorButton& colorButtonCyan, ColorButton& colorButtonGreen, bool& modoAgregarRutas, List<sf::Vector2f>& listCoordenates, bool& mostrarLineas, bool& mostrarRutas, sf::Text& infoText);

	// Actualiza el color de las lineas segun los botones de color presionados
	void updateColorButtons(const sf::RenderWindow& window, sf::Color& lineColor, const ColorButton& colorButtonRed, const ColorButton& colorButtonBlue, const ColorButton& colorButtonYellow, const ColorButton& colorButtonMagenta, const ColorButton& colorButtonCyan, const ColorButton& colorButtonGreen);

	// Metodo para manejar las interacciones de los botones
	void handleButtons(sf::RenderWindow& window, Button& finalizarRutaButton, Button& guardarRutaButton, Button& ocultarRutaButton, Button& mostrarRutaButton, bool& modoAgregarRutas, bool& showText, List<sf::Vector2f>& listCoordenates, bool& mostrarLineas, sf::Text& infoText);
};
