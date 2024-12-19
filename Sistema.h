#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
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
    void eliminarPaciente();
    void modificarPaciente();
    void buscarPaciente();
    void registrarHistorial();

    void registrarMedico();
    void eliminarMedico();
    void listarMedicosPorEspecialidad();

    void asignarCita();
    void mostrarPacientes() const;
    void mostrarMedicos() const;
    void mostrarCitas() const;
};

#endif
