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
    //pacientes

    void registrarPaciente();
    bool eliminarPaciente(const std::string& id); // Ahora devuelve un bool y recibe un ID
    void modificarPaciente(const std::string& id);
    void buscarPaciente();
    void mostrarPacientes() const;
    void buscarPacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin);
    void listarPacientesConEnfermedadesCronicas() const;
    void buscarPacientesPorNombre() const;

    //historial

    void registrarHistorial();

    //medicos

    void registrarMedico();
    bool eliminarMedico(const std::string& id); // Ahora recibe un ID y devuelve un bool
    void listarMedicosPorEspecialidad();
    void mostrarMedicos() const;
    void listarCitasPorMedicoOEspecialidad() const;

    //citas

    void asignarCita();
    void mostrarCitas() const;
    void ordenarCitasPorFecha();
    void ordenarCitasPorUrgencia();
    void registrarCitaPasada();
    void eliminarCita();
    void modificarCita();

    //CSV

    void cargarPacientesDesdeCSV(const std::string& ruta);
    void guardarPacientesEnCSV(const std::string& ruta);
    void cargarMedicosDesdeCSV(const std::string& ruta);
    void guardarMedicosEnCSV(const std::string& ruta);
    void cargarCitasDesdeCSV(const std::string& ruta);
    void guardarCitasEnCSV(const std::string& ruta);

    //Backup

    void realizarBackup(const std::string& rutaBackup); // Método para realizar el respaldo.
    void restaurarDesdeBackup(const std::string& rutaBackup); // Nuevo método para restaurar.

};

#endif
