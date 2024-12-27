#include "Medico.h"

void Medico::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
        << "\nEspecialidad: " << especialidad << "\n";
}