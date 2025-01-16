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
    // Declaración del constructor sin definición en el archivo de encabezado
    Cita(std::string id, const Paciente* paciente, const Medico* medico,
        std::string fecha, std::string hora, std::string motivo, int urgencia);

    // Métodos getter
    const Paciente* getPaciente() const;
    const Medico* getMedico() const;
    std::string getFecha() const;
    std::string getHora() const;
    std::string getMotivo() const;
    int getUrgencia() const;
    std::string getId() const; // Agregar getter para ID

    // Métodos setter (si es necesario)
    void setFecha(const std::string& fecha);  // Agregar setter para Fecha
    void setHora(const std::string& hora);    // Agregar setter para Hora
    void setMotivo(const std::string& motivo); // Agregar setter para Motivo
    void setUrgencia(int urgencia);           // Agregar setter para Urgencia

    void mostrarInformacion() const;
   
    std::string toCSV() const; // Serializa una cita a CSV.
    static Cita fromCSV(const std::string& lineaCSV,
        const std::vector<Paciente>& pacientes,
        const std::vector<Medico>& medicos); // Carga desde CSV.
};

#endif
