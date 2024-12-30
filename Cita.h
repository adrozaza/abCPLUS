#ifndef CITA_H
#define CITA_H

#include <string>
#include <iostream>
#include "Paciente.h"
#include "Medico.h"

class Cita {
private:
    std::string id;             // ID único de la cita
    const Paciente* paciente;   // Puntero constante al paciente
    const Medico* medico;       // Puntero constante al médico
    std::string fecha;          // Fecha de la cita en formato YYYY-MM-DD
    std::string hora;           // Hora de la cita en formato HH:MM
    std::string motivo;         // Motivo de la cita
    int urgencia;               // Nivel de urgencia: 1 = Alta, 2 = Media, 3 = Baja

public:
    // Constructor
    Cita(std::string id, const Paciente* paciente, const Medico* medico,
        std::string fecha, std::string hora, std::string motivo, int urgencia);


    // Métodos de acceso
    std::string getFecha() const;
    int getUrgencia() const;

    std::string getId() const { return id; }
    void setFecha(const std::string& nuevaFecha) { fecha = nuevaFecha; }
    void setHora(const std::string& nuevaHora) { hora = nuevaHora; }
    void setMotivo(const std::string& nuevoMotivo) { motivo = nuevoMotivo; }
    void setUrgencia(int nuevaUrgencia) { urgencia = nuevaUrgencia; }

    // Método de presentación
    void mostrarInformacion() const;
};

#endif
