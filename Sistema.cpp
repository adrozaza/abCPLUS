#include "Sistema.h"
#include <iostream>
#include <algorithm>

// Mantén las funciones originales como estaban.
void Sistema::registrarPaciente() {
    std::string id, nombre, fechaNacimiento, direccion, telefono, email;
    std::cout << "Ingrese los datos del paciente:\n";
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Fecha de Nacimiento (YYYY-MM-DD): ";
    std::cin >> fechaNacimiento;
    std::cin.ignore();

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

void Sistema::eliminarPaciente() {
    std::string id;
    std::cout << "Ingrese el ID del paciente a eliminar: ";
    std::cin >> id;

    auto it = std::remove_if(pacientes.begin(), pacientes.end(), [&](const Paciente& p) {
        return p.getId() == id;
        });

    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        std::cout << "Paciente eliminado con éxito.\n";
    }
    else {
        std::cout << "Paciente no encontrado.\n";
    }
}

void Sistema::modificarPaciente() {
    std::string id;
    std::cout << "Ingrese el ID del paciente a modificar: ";
    std::cin >> id;

    for (auto& paciente : pacientes) {
        if (paciente.getId() == id) {
            std::cout << "Ingrese nuevos datos:\n";
            std::string nombre, direccion, telefono, email;

            std::cout << "Nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            paciente.setNombre(nombre);

            std::cout << "Dirección: ";
            std::getline(std::cin, direccion);
            paciente.setDireccion(direccion);

            std::cout << "Teléfono: ";
            std::cin >> telefono;
            paciente.setTelefono(telefono);

            std::cout << "Email: ";
            std::cin >> email;
            paciente.setEmail(email);

            std::cout << "Paciente modificado con éxito.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Sistema::buscarPaciente() {
    std::string criterio;
    std::cout << "Ingrese el nombre o ID del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, criterio);

    for (const auto& paciente : pacientes) {
        if (paciente.getId() == criterio || paciente.getNombre() == criterio) {
            paciente.mostrarInformacion();
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Sistema::registrarHistorial() {
    std::string id, historial;
    std::cout << "Ingrese el ID del paciente: ";
    std::cin >> id;
    for (auto& paciente : pacientes) {
        if (paciente.getId() == id) {
            std::cout << "Ingrese el historial clínico: ";
            std::cin.ignore();
            std::getline(std::cin, historial);
            paciente.agregarHistorial(historial);
            std::cout << "Historial registrado con éxito.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Sistema::eliminarMedico() {
    std::string id;
    std::cout << "Ingrese el ID del médico a eliminar: ";
    std::cin >> id;

    auto it = std::remove_if(medicos.begin(), medicos.end(), [&](const Medico& m) {
        return m.getId() == id;
        });

    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        std::cout << "Médico eliminado con éxito.\n";
    }
    else {
        std::cout << "Médico no encontrado.\n";
    }
}

void Sistema::listarMedicosPorEspecialidad() {
    std::string especialidad;
    std::cout << "Ingrese la especialidad: ";
    std::cin.ignore();
    std::getline(std::cin, especialidad);

    bool encontrado = false;
    for (const auto& medico : medicos) {
        if (medico.getEspecialidad() == especialidad) {
            medico.mostrarInformacion();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron médicos con esa especialidad.\n";
    }
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
