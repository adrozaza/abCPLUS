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

    // Métodos de acceso
    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getEspecialidad() const { return especialidad; }

    // Métodos de presentación
    void mostrarInformacion() const;

    // Constructor por defecto
    Medico() = default;

    std::string toCSV() const; // Serializa un médico a CSV.
    static Medico fromCSV(const std::string& lineaCSV); // Carga desde CSV.
};

#endif