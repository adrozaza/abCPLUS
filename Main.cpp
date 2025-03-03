#include <windows.h>
#include <iostream>
#include "Sistema.h"

void mostrarMenuPrincipal() {
    system("cls");
    std::cout << "--- Sistema de Gestión Hospitalaria ---\n";
    std::cout << "1. Gestión de Pacientes\n";
    std::cout << "2. Gestión de Médicos\n";
    std::cout << "3. Gestión de Citas\n";
    std::cout << "4. Backup de la Base de Datos\n"; // Opción de submenú
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

//pacientes

void menuBuscarPacientes(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Submenú: Buscar Pacientes ---\n";
        std::cout << "1. Buscar Pacientes por Fecha\n";
        std::cout << "2. Buscar Pacientes por Nombre\n";
        std::cout << "3. Buscar Pacientes por Enfermedades Crónicas\n";
        std::cout << "4. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1: {
            std::string fechaInicio, fechaFin;
            std::cout << "Ingrese la fecha de inicio (YYYY-MM-DD): ";
            std::cin >> fechaInicio;
            std::cout << "Ingrese la fecha de fin (YYYY-MM-DD): ";
            std::cin >> fechaFin;
            sistema.buscarPacientesPorFecha(fechaInicio, fechaFin);
            break;
        }
        case 2:
            sistema.buscarPacientesPorNombre();
            break;
        case 3:
            sistema.listarPacientesConEnfermedadesCronicas();
            break;
        case 4:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }

        if (opcion != 4) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 4);
}

void menuHistorial(Sistema& sistema) {
    int opcionHistorial;
    do {
        system("cls");
        std::cout << "--- Menú de Historial ---\n";
        std::cout << "1. Registrar Historial\n";
        std::cout << "2. Revisar Historial\n";
        std::cout << "3. Volver al Menú Pacientes\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionHistorial;
        std::cin.ignore();

        switch (opcionHistorial) {
        case 1:
            sistema.registrarHistorial();
            break;
        case 2: {
            std::string id;
            std::cout << "Ingrese el ID del paciente para revisar su historial: ";
            std::cin >> id;
            sistema.revisarHistorial(id);
            break;
        }
        case 3:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }

        if (opcionHistorial != 3) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (opcionHistorial != 3);
}


void menuPacientes(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Gestión de Pacientes ---\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Mostrar Pacientes\n";
        std::cout << "3. Eliminar Paciente\n";
        std::cout << "4. Buscar Pacientes\n"; // Accede al submenú
        std::cout << "5. Modificar Paciente\n";
        std::cout << "6. Historial\n";
        std::cout << "7. Volver al Menú Principal\n";
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
        case 3: {
            std::string id;
            std::cout << "Ingrese el ID del paciente a eliminar: ";
            std::cin >> id;
            if (sistema.eliminarPaciente(id)) {
                std::cout << "Paciente eliminado con éxito.\n";
            }
            else {
                std::cout << "Paciente no encontrado.\n";
            }
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 4:
            menuBuscarPacientes(sistema);
            break;
        case 5: {
            std::string id;
            std::cout << "Ingrese el ID del paciente a modificar: ";
            std::cin >> id;
            sistema.modificarPaciente(id);
            break;
        }
        case 6:
            menuHistorial(sistema);
            break;
        case 7:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }

        if (opcion != 7) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 7);
}

//medicos

void menuMedicos(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Gestión de Médicos ---\n";
        std::cout << "1. Registrar Médico\n";
        std::cout << "2. Mostrar Médicos\n";
        std::cout << "3. Eliminar Médico\n";
        std::cout << "4. Mostrar Médicos por Especialidad\n";
        std::cout << "5. Volver al Menú Principal\n";
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
        case 3: {
            std::string id;
            std::cout << "Ingrese el ID del médico a eliminar: ";
            std::cin >> id;
            if (sistema.eliminarMedico(id)) {
                std::cout << "Médico eliminado con éxito.\n";
            }
            else {
                std::cout << "Médico no encontrado.\n";
            }
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 4:
            sistema.listarMedicosPorEspecialidad();
            break;
        case 5:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        if (opcion != 5) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 5);
}

// citas

void menuBuscarCitas(Sistema& sistema) {
    int opcion;
    do {
        system("cls");
        std::cout << "--- Submenú: Buscar Citas ---\n";
        std::cout << "1. Ordenar Citas por Fecha\n";
        std::cout << "2. Ordenar Citas por Urgencia\n";
        std::cout << "3. Listar Citas por Médico o Especialidad\n";
        std::cout << "4. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            sistema.ordenarCitasPorFecha();
            sistema.mostrarCitas();
            break;
        case 2:
            sistema.ordenarCitasPorUrgencia();
            sistema.mostrarCitas();
            break;
        case 3:
            sistema.listarCitasPorMedicoOEspecialidad();
            break;
        case 4:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
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
        std::cout << "2. Registrar cita pasada\n";
        std::cout << "3. Mostrar Citas\n";
        std::cout << "4. Buscar Citas\n"; // Accede al submenú
        std::cout << "5. Eliminar Cita\n";
        std::cout << "6. Modificar Cita\n";
        std::cout << "7. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            sistema.asignarCita();
            break;
        case 2:
            sistema.registrarCitaPasada();
            break;
        case 3:
            sistema.mostrarCitas();
            break;
        case 4:
            menuBuscarCitas(sistema);
            break;
        case 5:
            sistema.eliminarCita();
            break;
        case 6:
            sistema.modificarCita();
            break;
        case 7:
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        if (opcion != 7) {
            std::cout << "\nPresione cualquier tecla para continuar...";
            std::cin.get();
        }
    } while (opcion != 7);
}

//Backup

void menuBackup(Sistema& sistema) {
    int opcionBackup;
    do {
        system("cls");
        std::cout << "--- Menú de Backup ---\n";
        std::cout << "1. Realizar Backup de la Base de Datos\n";
        std::cout << "2. Restaurar Datos desde un Respaldo\n";
        std::cout << "3. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionBackup;
        std::cin.ignore();

        switch (opcionBackup) {
        case 1: {
            std::string rutaBackup;
            std::cout << "Ingrese la ruta donde desea guardar el backup: ";
            std::cin >> rutaBackup;
            sistema.realizarBackup(rutaBackup);
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 2: {
            std::string rutaBackup;
            std::cout << "Ingrese la ruta del respaldo a restaurar: ";
            std::cin >> rutaBackup;
            sistema.restaurarDesdeBackup(rutaBackup);
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 3:
            std::cout << "Volviendo al menú principal...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (opcionBackup != 3);
}

//main

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Sistema sistema;
    // Cargar datos al inicio
    sistema.cargarPacientesDesdeCSV("pacientes.csv");
    sistema.cargarMedicosDesdeCSV("medicos.csv");
    sistema.cargarCitasDesdeCSV("citas.csv");

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
            menuBackup(sistema); // Llama al submenú de backup
            break;
        case 5:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (opcion != 5);

    sistema.guardarPacientesEnCSV("pacientes.csv");
    sistema.guardarMedicosEnCSV("medicos.csv");
    sistema.guardarCitasEnCSV("citas.csv");

    return 0;
}