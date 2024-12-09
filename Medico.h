#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <iostream>

class Medico {
private:
    std::string id;
    std::string nombre;
    std::string especialidad;

public:
    Medico(std::string id, std::string nombre, std::string especialidad)
        : id(id), nombre(nombre), especialidad(especialidad) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    void mostrarInformacion() const;
};

#endif
