#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

class Paciente {
private:
    std::string id;
    std::string nombre;
    std::string fechaNacimiento;
    std::string direccion;
    std::string telefono;
    std::string email;

public:
    Paciente(std::string id, std::string nombre, std::string fechaNacimiento,
        std::string direccion, std::string telefono, std::string email)
        : id(id), nombre(nombre), fechaNacimiento(fechaNacimiento),
        direccion(direccion), telefono(telefono), email(email) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    void mostrarInformacion() const;

    Paciente() = default;
};

#endif
