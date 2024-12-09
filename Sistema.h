#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class Sistema {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<Cita> citas;

public:
    void registrarPaciente();
    void registrarMedico();
    void asignarCita();
    void mostrarPacientes() const;
    void mostrarMedicos() const;
    void mostrarCitas() const;
};

#endif
