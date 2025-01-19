#include "Paciente.h"
#include <sstream>

void Paciente::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
        << "\nFecha de Nacimiento: " << fechaNacimiento
        << "\nDirección: " << direccion << "\nTeléfono: " << telefono
        << "\nEmail: " << email
        << "\nEnfermedades Cronicas: " << enfermedadesCronicas << "\n";
}

std::string Paciente::toCSV() const {
    return id + "," + nombre + "," + fechaNacimiento + "," + direccion + "," + telefono + "," + email + "," + enfermedadesCronicas;
}

Paciente Paciente::fromCSV(const std::string& lineaCSV) {
    std::stringstream ss(lineaCSV);
    std::string id, nombre, fechaNacimiento, direccion, telefono, email, enfermedadesCronicas;
    std::getline(ss, id, ',');
    std::getline(ss, nombre, ',');
    std::getline(ss, fechaNacimiento, ',');
    std::getline(ss, direccion, ',');
    std::getline(ss, telefono, ',');
    std::getline(ss, email, ',');
    std::getline(ss, enfermedadesCronicas, ',');
    return Paciente(id, nombre, fechaNacimiento, direccion, telefono, email, enfermedadesCronicas);
}

std::string Paciente::getDireccion() const {
    return direccion;
}

std::string Paciente::getTelefono() const {
    return telefono;
}

std::string Paciente::getEmail() const {
    return email;
}