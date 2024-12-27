#include <windows.h>
#include "Sistema.h"

int main() {
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
        std::cout << "6. Mostrar por especialidad\n";
        std::cout << "7. Mostrar Citas\n";
        std::cout << "8. Registrar historial\n";
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
            sistema.listarMedicosPorEspecialidad();
            break;
        case 7:
            sistema.mostrarCitas();
            break;
        case 8:
            sistema.registrarHistorial();
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