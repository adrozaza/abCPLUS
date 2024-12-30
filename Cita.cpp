#include "Cita.h"

// Constructor
Cita::Cita(std::string id, const Paciente* paciente, const Medico* medico,
    std::string fecha, std::string hora, std::string motivo, int urgencia)
    : id(std::move(id)), paciente(paciente), medico(medico),
    fecha(std::move(fecha)), hora(std::move(hora)),
    motivo(std::move(motivo)), urgencia(urgencia) {}

// Métodos de acceso
std::string Cita::getFecha() const {
    return fecha;
}

int Cita::getUrgencia() const {
    return urgencia;
}

// Método de presentación
void Cita::mostrarInformacion() const {
    std::cout << "ID Cita: " << id << "\n"
        << "Paciente: " << (paciente ? paciente->getNombre() : "N/A") << "\n"
        << "Médico: " << (medico ? medico->getNombre() : "N/A") << "\n"
        << "Fecha: " << fecha << "\n"
        << "Hora: " << hora << "\n"
        << "Motivo: " << motivo << "\n"
        << "Urgencia: " << urgencia << "\n";
}
