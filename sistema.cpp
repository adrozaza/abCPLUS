#include "Sistema.h"
#include <iostream>
#include <string>

void Sistema::registrarPaciente() {
    std::string id, nombre, fechaNacimiento, direccion, telefono, email;
    std::cout << "Ingrese los datos del paciente:\n";
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(); // Limpiar el flujo antes de usar getline

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Fecha de Nacimiento (YYYY-MM-DD): ";
    std::cin >> fechaNacimiento;
    std::cin.ignore(); // Limpiar el flujo antes de usar getline

    std::cout << "Dirección: ";
    std::getline(std::cin, direccion);

    std::cout << "Teléfono: ";
    std::cin >> telefono;
    std::cin.ignore();

    std::cout << "Email: ";
    std::cin >> email;
    std::cin.ignore();

    pacientes.emplace_back(id, nombre, fechaNacimiento, direccion, telefono, email);
    std::cout << "Paciente registrado con éxito.\n";
}
void Sistema::registrarMedico() {
    std::string id, nombre, especialidad;
    std::cout << "Ingrese los datos del médico:\n";
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Especialidad: ";
    std::getline(std::cin, especialidad);

    medicos.emplace_back(id, nombre, especialidad);
    std::cout << "Médico registrado con éxito.\n";
}

void Sistema::asignarCita() {
    if (pacientes.empty() || medicos.empty()) {
        std::cout << "Debe registrar al menos un paciente y un médico antes de asignar una cita.\n";
        return;
    }

    std::string id, pacienteId, medicoId, fecha, hora, motivo;
    std::cout << "Ingrese los datos de la cita:\n";
    std::cout << "ID Cita: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "ID Paciente: ";
    std::cin >> pacienteId;
    std::cout << "ID Médico: ";
    std::cin >> medicoId;
    std::cin.ignore();
    std::cout << "Fecha (YYYY-MM-DD): ";
    std::cin >> fecha;
    std::cout << "Hora (HH:MM): ";
    std::cin >> hora;
    std::cin.ignore();
    std::cout << "Motivo: ";
    std::getline(std::cin, motivo);

    // Buscar paciente y médico
    Paciente* paciente = nullptr;
    Medico* medico = nullptr;

    for (auto& p : pacientes) {
        if (p.getId() == pacienteId) {
            paciente = &p;
            break;
        }
    }

    for (auto& m : medicos) {
        if (m.getId() == medicoId) {
            medico = &m;
            break;
        }
    }

    if (paciente && medico) {
        citas.emplace_back(id, *paciente, *medico, fecha, hora, motivo);
        std::cout << "Cita asignada con éxito.\n";
    }
    else {
        std::cout << "Paciente o médico no encontrados.\n";
    }
}

void Sistema::mostrarPacientes() const {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
    }
    else {
        for (const auto& paciente : pacientes) {
            paciente.mostrarInformacion();
            std::cout << "-------------------------\n";
        }
    }
}

void Sistema::mostrarMedicos() const {
    if (medicos.empty()) {
        std::cout << "No hay médicos registrados.\n";
    }
    else {
        for (const auto& medico : medicos) {
            medico.mostrarInformacion();
            std::cout << "-------------------------\n";
        }
    }
}

void Sistema::mostrarCitas() const {
    if (citas.empty()) {
        std::cout << "No hay citas registradas.\n";
    }
    else {
        for (const auto& cita : citas) {
            cita.mostrarInformacion();
            std::cout << "-------------------------\n";
        }
    }
}
