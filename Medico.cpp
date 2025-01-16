#include "Medico.h"
#include <sstream>

void Medico::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
        << "\nEspecialidad: " << especialidad << "\n";
}

std::string Medico::toCSV() const {
    return id + "," + nombre + "," + especialidad;
}

Medico Medico::fromCSV(const std::string& lineaCSV) {
    std::stringstream ss(lineaCSV);
    std::string id, nombre, especialidad;
    std::getline(ss, id, ',');
    std::getline(ss, nombre, ',');
    std::getline(ss, especialidad, ',');

    return Medico(id, nombre, especialidad);
}