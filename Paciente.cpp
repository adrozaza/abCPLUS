#include "Paciente.h"

void Paciente::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
        << "\nFecha de Nacimiento: " << fechaNacimiento
        << "\nDirección: " << direccion << "\nTeléfono: " << telefono
        << "\nEmail: " << email << "\n";
}
