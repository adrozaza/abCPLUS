#include "Sistema.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <filesystem>

//pacientes

void Sistema::registrarPaciente() {
    std::string id, nombre, fechaNacimiento, direccion, telefono, email, enfermedadesCronicas;
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

    std::cout << "Enfermedades Crónicas (si no tiene, deje en blanco): ";
    std::getline(std::cin, enfermedadesCronicas);

    pacientes.emplace_back(id, nombre, fechaNacimiento, direccion, telefono, email, enfermedadesCronicas);
    std::cout << "Paciente registrado con éxito.\n";
}

bool Sistema::eliminarPaciente(const std::string& id) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
        [&id](const Paciente& paciente) {
            return paciente.getId() == id;
        });

    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        return true; // Paciente eliminado
    }

    return false; // Paciente no encontrado
}

void Sistema::modificarPaciente(const std::string& id) {
    for (auto& paciente : pacientes) {
        if (paciente.getId() == id) {
            std::cout << "Ingrese nuevos datos o deje en blanco para no modificar:\n";
            std::string nombre, direccion, telefono, email, enfermedadesCronicas;

            // Modificar nombre
            std::cout << "Nombre (Actual: " << paciente.getNombre() << "): ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            if (!nombre.empty()) {
                paciente.setNombre(nombre);
            }

            // Modificar dirección
            std::cout << "Dirección (Actual: " << paciente.getDireccion() << "): ";
            std::getline(std::cin, direccion);
            if (!direccion.empty()) {
                paciente.setDireccion(direccion);
            }

            // Modificar teléfono
            std::cout << "Teléfono (Actual: " << paciente.getTelefono() << "): ";
            std::getline(std::cin, telefono);
            if (!telefono.empty()) {
                paciente.setTelefono(telefono);
            }

            // Modificar email
            std::cout << "Email (Actual: " << paciente.getEmail() << "): ";
            std::getline(std::cin, email);
            if (!email.empty()) {
                paciente.setEmail(email);
            }

            // Modificar enfermedades crónicas
            std::cout << "Enfermedades Crónicas (Actual: " << paciente.getEnfermedadesCronicas() << "): ";
            std::getline(std::cin, enfermedadesCronicas);
            if (!enfermedadesCronicas.empty()) {
                paciente.setEnfermedadesCronicas(enfermedadesCronicas);
            }

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

void Sistema::buscarPacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin) {
    bool encontrado = false;  // Bandera para verificar si se encontró algún paciente

    for (const auto& cita : citas) {
        if (cita.getFecha() >= fechaInicio && cita.getFecha() <= fechaFin) {
            cita.getPaciente()->mostrarInformacion();  // Mostramos los datos del paciente
            std::cout << "-------------------------\n";
            encontrado = true;  // Marcamos que se encontró al menos un paciente
        }
    }

    // Si no se encontró ningún paciente, mostrar un mensaje
    if (!encontrado) {
        std::cout << "No se encontraron pacientes en el rango de fechas proporcionado.\n";
    }
    std::cin.get();
}

void Sistema::listarPacientesConEnfermedadesCronicas() const {
    bool encontrado = false;
    std::cout << "--- Pacientes con Enfermedades Crónicas ---\n";

    for (const auto& paciente : pacientes) {
        if (!paciente.getEnfermedadesCronicas().empty()) { // Verifica si tiene enfermedades crónicas
            paciente.mostrarInformacion();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron pacientes con enfermedades crónicas.\n";
    }
}

void Sistema::buscarPacientesPorNombre() const {
    std::string nombreBuscado;
    std::cout << "Ingrese el nombre o parte del nombre del paciente a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreBuscado);

    bool encontrado = false;
    std::cout << "--- Resultados de la Búsqueda ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getNombre().find(nombreBuscado) != std::string::npos) { // Búsqueda parcial
            paciente.mostrarInformacion();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron pacientes con el nombre proporcionado.\n";
    }
}

//historial

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

//medicos

bool Sistema::eliminarMedico(const std::string& id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [&id](const Medico& medico) {
            return medico.getId() == id;
        });

    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        return true; // Médico eliminado con éxito
    }

    return false; // Médico no encontrado
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

//citas

void Sistema::asignarCita() {
    if (pacientes.empty() || medicos.empty()) {
        std::cout << "Debe registrar al menos un paciente y un médico antes de asignar una cita.\n";
        return;
    }

    std::string id, pacienteId, medicoId, fecha, hora, motivo;
    int urgencia;

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

    std::cout << "Urgencia (1 = Alta, 2 = Media, 3 = Baja): ";
    std::cin >> urgencia;

    // Buscar paciente y médico
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

    if (paciente && medico) {
        citas.emplace_back(id, paciente, medico, fecha, hora, motivo, urgencia);
        std::cout << "Cita asignada con éxito.\n";
    }
    else {
        std::cout << "Paciente o médico no encontrados.\n";
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

void Sistema::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(), [](const Cita& a, const Cita& b) {
        return a.getFecha() < b.getFecha(); // Comparación lexicográfica de las fechas
        });
    std::cout << "Citas ordenadas por fecha.\n";
}

void Sistema::ordenarCitasPorUrgencia() {
    std::sort(citas.begin(), citas.end(), [](const Cita& a, const Cita& b) {
        return a.getUrgencia() < b.getUrgencia(); // Menor nivel de urgencia primero
        });
    std::cout << "Citas ordenadas por urgencia.\n";
}

void Sistema::registrarCitaPasada() {
    std::string id, pacienteId, medicoId, fecha, hora, motivo;
    int urgencia;
    std::cout << "Ingrese los datos de la cita pasada:\n";
    std::cout << "ID Cita: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "ID Paciente: ";
    std::cin >> pacienteId;
    const Paciente* paciente = nullptr;
    for (const auto& p : pacientes) {
        if (p.getId() == pacienteId) {
            paciente = &p;
            break;
        }
    }

    if (!paciente) {
        std::cout << "Paciente no encontrado.\n";
        return;
    }

    std::cout << "ID Médico: ";
    std::cin >> medicoId;
    const Medico* medico = nullptr;
    for (const auto& m : medicos) {
        if (m.getId() == medicoId) {
            medico = &m;
            break;
        }
    }

    if (!medico) {
        std::cout << "Médico no encontrado.\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Fecha (YYYY-MM-DD): ";
    std::cin >> fecha;

    std::cout << "Hora (HH:MM): ";
    std::cin >> hora;

    std::cin.ignore();
    std::cout << "Motivo: ";
    std::getline(std::cin, motivo);

    std::cout << "Urgencia (1 = Alta, 2 = Media, 3 = Baja): ";
    std::cin >> urgencia;

    citas.emplace_back(id, paciente, medico, fecha, hora, motivo, urgencia);
    std::cout << "Cita pasada registrada con éxito.\n";
}

void Sistema::eliminarCita() {
    std::string id;
    std::cout << "Ingrese el ID de la cita a eliminar: ";
    std::cin >> id;

    auto it = std::remove_if(citas.begin(), citas.end(), [&](const Cita& c) {
        return c.getId() == id;
        });

    if (it != citas.end()) {
        citas.erase(it, citas.end());
        std::cout << "Cita eliminada con éxito.\n";
    }
    else {
        std::cout << "Cita no encontrada.\n";
    }
}

void Sistema::modificarCita() {
    std::string id;
    std::cout << "Ingrese el ID de la cita a modificar: ";
    std::cin >> id;

    for (auto& cita : citas) {
        if (cita.getId() == id) {
            std::cout << "Ingrese nuevos datos:\n";
            std::string nuevaFecha, nuevaHora, nuevoMotivo;
            int nuevaUrgencia;

            std::cout << "Nueva Fecha (YYYY-MM-DD): ";
            std::cin >> nuevaFecha;
            cita.setFecha(nuevaFecha);

            std::cout << "Nueva Hora (HH:MM): ";
            std::cin >> nuevaHora;
            cita.setHora(nuevaHora);

            std::cout << "Nuevo Motivo: ";
            std::cin.ignore();
            std::getline(std::cin, nuevoMotivo);
            cita.setMotivo(nuevoMotivo);

            std::cout << "Nueva Urgencia (1 = Alta, 2 = Media, 3 = Baja): ";
            std::cin >> nuevaUrgencia;
            cita.setUrgencia(nuevaUrgencia);

            std::cout << "Cita modificada con éxito.\n";
            return;
        }
    }
    std::cout << "Cita no encontrada.\n";
}

void Sistema::listarCitasPorMedicoOEspecialidad() const {
    int opcion;
    std::cout << "--- Listar Citas por Médico o Especialidad ---\n";
    std::cout << "1. Listar por Médico\n";
    std::cout << "2. Listar por Especialidad\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    std::cin.ignore();

    if (opcion == 1) {
        std::string idMedico;
        std::cout << "Ingrese el ID del médico: ";
        std::cin >> idMedico;
        std::cin.ignore();

        bool encontrado = false;
        for (const auto& cita : citas) {
            if (cita.getMedico()->getId() == idMedico) {
                cita.mostrarInformacion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            std::cout << "No se encontraron citas para el médico con ID: " << idMedico << "\n";
        }
    }
    else if (opcion == 2) {
        std::string especialidad;
        std::cout << "Ingrese la especialidad: ";
        std::getline(std::cin, especialidad);

        bool encontrado = false;
        for (const auto& cita : citas) {
            if (cita.getMedico()->getEspecialidad() == especialidad) {
                cita.mostrarInformacion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            std::cout << "No se encontraron citas para la especialidad: " << especialidad << "\n";
        }
    }
    else {
        std::cout << "Opción inválida.\n";
    }
}

//csv

void Sistema::cargarMedicosDesdeCSV(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        medicos.push_back(Medico::fromCSV(linea));
    }
    archivo.close();
}

void Sistema::guardarMedicosEnCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    for (const auto& medico : medicos) {
        archivo << medico.toCSV() << "\n";
    }
    archivo.close();
}

void Sistema::cargarCitasDesdeCSV(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        try {
            citas.push_back(Cita::fromCSV(linea, pacientes, medicos));
        }
        catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }
    archivo.close();
}

void Sistema::guardarCitasEnCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    for (const auto& cita : citas) {
        archivo << cita.toCSV() << "\n";
    }
    archivo.close();
}

void Sistema::cargarPacientesDesdeCSV(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        pacientes.push_back(Paciente::fromCSV(linea));
    }
    archivo.close();
}

void Sistema::guardarPacientesEnCSV(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << ruta << "\n";
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.toCSV() << "\n";
    }
    archivo.close();
}

//backup

void Sistema::realizarBackup(const std::string& rutaBackup) {
    // Crear carpeta de respaldo si no existe
    if (!std::filesystem::exists(rutaBackup)) {
        std::filesystem::create_directory(rutaBackup);
    }

    // Obtener fecha y hora actuales
    auto ahora = std::time(nullptr);
    std::tm tiempoLocal;
    localtime_s(&tiempoLocal, &ahora); // Para Windows, usa localtime_r en Linux/MacOS

    // Crear un sufijo con la fecha y hora en formato YYYYMMDD_HHMMSS
    std::ostringstream sufijo;
    sufijo << std::put_time(&tiempoLocal, "%Y%m%d_%H%M%S");

    // Rutas para los respaldos
    std::string rutaPacientes = rutaBackup + "/pacientes_" + sufijo.str() + ".csv";
    std::string rutaMedicos = rutaBackup + "/medicos_" + sufijo.str() + ".csv";
    std::string rutaCitas = rutaBackup + "/citas_" + sufijo.str() + ".csv";

    // Copiar archivos actuales a las rutas de respaldo
    guardarPacientesEnCSV(rutaPacientes);
    guardarMedicosEnCSV(rutaMedicos);
    guardarCitasEnCSV(rutaCitas);

    std::cout << "Respaldo realizado exitosamente en la carpeta: " << rutaBackup << "\n";
}

void Sistema::restaurarDesdeBackup(const std::string& rutaBackup) {
    // Obtener los nombres de los archivos en el directorio de respaldo
    std::vector<std::string> archivosEncontrados;
    for (const auto& entry : std::filesystem::directory_iterator(rutaBackup)) {
        archivosEncontrados.push_back(entry.path().filename().string());
    }

    bool archivosEncontradosCorrectamente = false;

    for (const auto& nombreArchivo : archivosEncontrados) {
        if (nombreArchivo.find("pacientes_") != std::string::npos) {
            std::string archivoPacientes = rutaBackup + "/" + nombreArchivo;
            if (std::filesystem::exists(archivoPacientes)) {
                cargarPacientesDesdeCSV(archivoPacientes);
                archivosEncontradosCorrectamente = true;
            }
        }
        if (nombreArchivo.find("medicos_") != std::string::npos) {
            std::string archivoMedicos = rutaBackup + "/" + nombreArchivo;
            if (std::filesystem::exists(archivoMedicos)) {
                cargarMedicosDesdeCSV(archivoMedicos);
                archivosEncontradosCorrectamente = true;
            }
        }
    }

    if (!archivosEncontradosCorrectamente) {
        std::cerr << "Error: No se encontraron los archivos de respaldo de médicos o pacientes en la ruta especificada.\n";
        return;
    }

    // Verificar que los archivos de médicos y pacientes hayan sido cargados correctamente
    if (pacientes.empty()) {
        std::cerr << "Error: No se encontraron pacientes en el archivo de respaldo.\n";
        return;
    }
    if (medicos.empty()) {
        std::cerr << "Error: No se encontraron médicos en el archivo de respaldo.\n";
        return;
    }

    // Limpiar las citas actuales antes de cargar las nuevas
    citas.clear();

    // Descargar las citas ahora que los médicos y pacientes han sido cargados
    for (const auto& nombreArchivo : archivosEncontrados) {
        if (nombreArchivo.find("citas_") != std::string::npos) {
            std::string archivoCitas = rutaBackup + "/" + nombreArchivo;
            if (std::filesystem::exists(archivoCitas)) {
                cargarCitasDesdeCSV(archivoCitas);
                archivosEncontradosCorrectamente = true;
            }
        }
    }

    if (citas.empty()) {
        std::cerr << "Error: No se encontraron citas en el archivo de respaldo.\n";
        return;
    }

    std::cout << "Restauración completada exitosamente desde el respaldo en: " << rutaBackup << "\n";
}
