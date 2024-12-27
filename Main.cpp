#include <windows.h>
#include <iostream>
#include "Sistema.h"

void mostrarMenuPrincipal() {
    system("cls");
    std::cout << "--- Sistema de Gestión Hospitalaria ---\n";
    std::cout << "1. Gestión de Pacientes\n";
    std::cout << "2. Gestión de Médicos\n";
    std::cout << "3. Gestión de Citas\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void menuPacientes(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Gestión de Pacientes ---\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Mostrar Pacientes\n";
        std::cout << "3. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            sistema.registrarPaciente();
            break;
        case 2:
            sistema.mostrarPacientes();
            break;
        case 3:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        if (opcion != 3) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 3);
}

void menuMedicos(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Gestión de Médicos ---\n";
        std::cout << "1. Registrar Médico\n";
        std::cout << "2. Mostrar Médicos\n";
        std::cout << "3. Mostrar Médicos por Especialidad\n";
        std::cout << "4. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            sistema.registrarMedico();
            break;
        case 2:
            sistema.mostrarMedicos();
            break;
        case 3:
            sistema.listarMedicosPorEspecialidad();
            break;
        case 4:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        if (opcion != 4) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 4);
}

void menuCitas(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Gestión de Citas ---\n";
        std::cout << "1. Asignar Cita\n";
        std::cout << "2. Mostrar Citas\n";
        std::cout << "3. Registrar Historial\n";
        std::cout << "4. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            sistema.asignarCita();
            break;
        case 2:
            sistema.mostrarCitas();
            break;
        case 3:
            sistema.registrarHistorial();
            break;
        case 4:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        if (opcion != 4) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 4);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Sistema sistema;
    int opcion;

    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            menuPacientes(sistema);
            break;
        case 2:
            menuMedicos(sistema);
            break;
        case 3:
            menuCitas(sistema);
            break;
        case 4:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 4);

    return 0;
}
