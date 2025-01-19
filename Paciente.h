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
    std::string enfermedadesCronicas; // Nueva variable para enfermedades crónicas
    std::vector<std::string> historialClinico;

public:
    Paciente(std::string id, std::string nombre, std::string fechaNacimiento,
        std::string direccion, std::string telefono, std::string email,
        std::string enfermedadesCronicas = "") // Constructor actualizado
        : id(id), nombre(nombre), fechaNacimiento(fechaNacimiento),
        direccion(direccion), telefono(telefono), email(email),
        enfermedadesCronicas(enfermedadesCronicas) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setDireccion(const std::string& nuevaDireccion) { direccion = nuevaDireccion; }
    void setTelefono(const std::string& nuevoTelefono) { telefono = nuevoTelefono; }
    void setEmail(const std::string& nuevoEmail) { email = nuevoEmail; }

    // Métodos para enfermedades crónicas
    std::string getEnfermedadesCronicas() const { return enfermedadesCronicas; }
    void setEnfermedadesCronicas(const std::string& nuevasEnfermedades) { enfermedadesCronicas = nuevasEnfermedades; }

    // Nuevos getters para dirección, teléfono y email
    std::string getDireccion() const;
    std::string getTelefono() const;
    std::string getEmail() const;

    void agregarHistorial(const std::string& entrada) { historialClinico.push_back(entrada); }
    void mostrarHistorial() const;
    void mostrarInformacion() const;

    std::string toCSV() const; // Serializa un paciente a CSV.
    static Paciente fromCSV(const std::string& lineaCSV); // Carga desde CSV.
};

#endif