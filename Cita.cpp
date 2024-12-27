#include "Cita.h"

void Cita::mostrarInformacion() const {
    std::cout << "ID Cita: " << id << "\nPaciente: " << paciente.getNombre()
        << "\nMédico: " << medico.getNombre() << "\nFecha: " << fecha
        << "\nHora: " << hora << "\nMotivo: " << motivo << "\n";
}