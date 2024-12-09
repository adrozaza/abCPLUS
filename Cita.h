#ifndef CITA_H
#define CITA_H

#include <string>
#include <iostream>
#include "Paciente.h"
#include "Medico.h"

class Cita {
private:
    std::string id;
    const Paciente& paciente; // Referencia constante
    const Medico& medico;     // Referencia constante
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    Cita(std::string id, const Paciente& paciente, const Medico& medico,
        std::string fecha, std::string hora, std::string motivo)
        : id(id), paciente(paciente), medico(medico), fecha(fecha), hora(hora), motivo(motivo) {}

    void mostrarInformacion() const;
};

#endif
