#include "Cita.h"
#include <iostream>
#include <sstream>

std::string Cita::toCSV() const {
    return id + "," + paciente->getId() + "," + medico->getId() + "," +
        fecha + "," + hora + "," + motivo + "," + std::to_string(urgencia);
}

Cita Cita::fromCSV(const std::string& lineaCSV,
    const std::vector<Paciente>& pacientes,
    const std::vector<Medico>& medicos) {
    std::stringstream ss(lineaCSV);
    std::string id, pacienteId, medicoId, fecha, hora, motivo;
    int urgencia;

    std::getline(ss, id, ',');
    std::getline(ss, pacienteId, ',');
    std::getline(ss, medicoId, ',');
    std::getline(ss, fecha, ',');
    std::getline(ss, hora, ',');
    std::getline(ss, motivo, ',');
    ss >> urgencia;

    // Busca el paciente y el médico correspondientes.
    const Paciente* paciente = nullptr;
    const Medico* medico = nullptr;

    for (const auto& p : pacientes) {
        if (p.getId() == pacienteId) {
            paciente = &p;
            break;
        }
    }

    for (const auto& m : medicos) {
        if (m.getId() == medicoId) {
            medico = &m;
            break;
        }
    }

    if (!paciente || !medico) {
        throw std::runtime_error("Error: Paciente o Médico no encontrados en el CSV.");
    }

    return Cita(id, paciente, medico, fecha, hora, motivo, urgencia);
}




// Definición del constructor
Cita::Cita(std::string id, const Paciente* paciente, const Medico* medico,
    std::string fecha, std::string hora, std::string motivo, int urgencia)
    : id(id), paciente(paciente), medico(medico), fecha(fecha),
    hora(hora), motivo(motivo), urgencia(urgencia) {}

const Paciente* Cita::getPaciente() const {
    return paciente;
}

const Medico* Cita::getMedico() const {
    return medico;
}

std::string Cita::getFecha() const {
    return fecha;
}

std::string Cita::getHora() const {
    return hora;
}

std::string Cita::getMotivo() const {
    return motivo;
}

int Cita::getUrgencia() const {
    return urgencia;
}

std::string Cita::getId() const {
    return id;  // Definición del getter para id
}

// Definiciones de los setters
void Cita::setFecha(const std::string& fecha) {
    this->fecha = fecha;
}

void Cita::setHora(const std::string& hora) {
    this->hora = hora;
}

void Cita::setMotivo(const std::string& motivo) {
    this->motivo = motivo;
}

void Cita::setUrgencia(int urgencia) {
    this->urgencia = urgencia;
}

void Cita::mostrarInformacion() const {
    std::cout << "ID Cita: " << id << "\nFecha: " << fecha
        << "\nHora: " << hora << "\nMotivo: " << motivo
        << "\nUrgencia: " << urgencia
        << "\nPaciente: " << paciente->getNombre()  // Usamos getNombre de Paciente
        << "\nMédico: " << medico->getNombre() << "\n";
}
