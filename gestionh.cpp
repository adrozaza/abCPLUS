#include <iostream>
#include <vector>
#include <string>
#include <Windows.h> // Para configurar la consola en Windows

// Clase Paciente
class Paciente {
private:
    std::string id;
    std::string nombre;
    std::string fechaNacimiento;
    std::string direccion;
    std::string telefono;
    std::string email;

public:
    Paciente(std::string id, std::string nombre, std::string fechaNacimiento, std::string direccion, std::string telefono, std::string email)
        : id(id), nombre(nombre), fechaNacimiento(fechaNacimiento), direccion(direccion), telefono(telefono), email(email) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }

    void mostrarInformacion() const {
        std::cout << "ID: " << id << "\nNombre: " << nombre << "\nFecha de Nacimiento: " << fechaNacimiento
            << "\nDirección: " << direccion << "\nTeléfono: " << telefono << "\nEmail: " << email << "\n";
    }
};

// Clase Medico
class Medico {
private:
    std::string id;
    std::string nombre;
    std::string especialidad;

public:
    Medico(std::string id, std::string nombre, std::string especialidad)
        : id(id), nombre(nombre), especialidad(especialidad) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }

    void mostrarInformacion() const {
        std::cout << "ID: " << id << "\nNombre: " << nombre << "\nEspecialidad: " << especialidad << "\n";
    }
};

// Clase Cita
class Cita {
private:
    std::string id;
    Paciente paciente;
    Medico medico;
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    Cita(std::string id, const Paciente& paciente, const Medico& medico, std::string fecha, std::string hora, std::string motivo)
        : id(id), paciente(paciente), medico(medico), fecha(fecha), hora(hora), motivo(motivo) {}

    void mostrarInformacion() const {
        std::cout << "ID Cita: " << id << "\nPaciente: " << paciente.getNombre() << "\nMédico: " << medico.getNombre()
            << "\nFecha: " << fecha << "\nHora: " << hora << "\nMotivo: " << motivo << "\n";
    }
};

// Sistema Principal
class Sistema {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<Cita> citas;

public:
    void registrarPaciente() {
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
        std::cout << "Email: ";
        std::cin >> email;

        pacientes.emplace_back(id, nombre, fechaNacimiento, direccion, telefono, email);
        std::cout << "Paciente registrado con éxito.\n";
    }

    void registrarMedico() {
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

    void asignarCita() {
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

    void mostrarPacientes() const {
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

    void mostrarMedicos() const {
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

    void mostrarCitas() const {
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
};

// Programa Principal
int main() {
    // Configurar la entrada y salida de la consola para UTF-8
    SetConsoleCP(CP_UTF8);         // Configura la entrada de la consola para UTF-8
    SetConsoleOutputCP(CP_UTF8);   // Configura la salida de la consola para UTF-8

    Sistema sistema;
    int opcion;

    do {
        std::cout << "\n--- Sistema de Gestión Hospitalaria ---\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Registrar Médico\n";
        std::cout << "3. Asignar Cita\n";
        std::cout << "4. Mostrar Pacientes\n";
        std::cout << "5. Mostrar Médicos\n";
        std::cout << "6. Mostrar Citas\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            sistema.registrarPaciente();
            break;
        case 2:
            sistema.registrarMedico();
            break;
        case 3:
            sistema.asignarCita();
            break;
        case 4:
            sistema.mostrarPacientes();
            break;
        case 5:
            sistema.mostrarMedicos();
            break;
        case 6:
            sistema.mostrarCitas();
            break;
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}