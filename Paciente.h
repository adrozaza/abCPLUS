#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>
#include <vector>

class Paciente {
private:
    std::string id;
    std::string nombre;
    std::string fechaNacimiento;
    std::string direccion;
    std::string telefono;
    std::string email;
    std::vector<std::string> historialClinico;

public:
    Paciente(std::string id, std::string nombre, std::string fechaNacimiento,
        std::string direccion, std::string telefono, std::string email)
        : id(id), nombre(nombre), fechaNacimiento(fechaNacimiento),
        direccion(direccion), telefono(telefono), email(email) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setDireccion(const std::string& nuevaDireccion) { direccion = nuevaDireccion; }
    void setTelefono(const std::string& nuevoTelefono) { telefono = nuevoTelefono; }
    void setEmail(const std::string& nuevoEmail) { email = nuevoEmail; }
    void agregarHistorial(const std::string& entrada) { historialClinico.push_back(entrada); }
    void mostrarInformacion() const;
};

#endif