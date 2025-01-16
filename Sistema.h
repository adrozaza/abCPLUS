#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class Sistema {
private:
    std::vector<Paciente> pacientes; // Lista de pacientes
    std::vector<Medico> medicos;     // Lista de médicos
    std::vector<Cita> citas;         // Lista de citas

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

    // Nuevas funciones
    void ordenarCitasPorFecha();
    void ordenarCitasPorUrgencia();

    void registrarCitaPasada();
    void eliminarCita();
    void modificarCita();

    void buscarPacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin);

    void cargarPacientesDesdeCSV(const std::string& ruta);
    void guardarPacientesEnCSV(const std::string& ruta);
    void cargarMedicosDesdeCSV(const std::string& ruta);
    void guardarMedicosEnCSV(const std::string& ruta);
    void cargarCitasDesdeCSV(const std::string& ruta);
    void guardarCitasEnCSV(const std::string& ruta);
};

#endif
