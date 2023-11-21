#include "CoordenatesFileManager.h"

void CoordenatesFileManager::SaveCoordinates(const List<sf::Vector2f>& coordinates, const std::string& nameFile)
{
    std::ofstream archivo(nameFile);

    if (archivo.is_open()) {
        // Usamos el nuevo método para obtener la cabeza
        Node<sf::Vector2f>* actual = coordinates.getHead();
        while (actual != nullptr) {
            archivo << "Coordenada: (" << actual->getDato().x << ", " << actual->getDato().y << ")\n";
            actual = actual->getNext();
        }
        archivo.close();
    }
    else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
}
