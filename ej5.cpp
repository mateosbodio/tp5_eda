/*
5. Se desea modelar las filas de un banco, de cada persona se sabe el DNI y la operación que desea realizar, según un menú de opciones las operaciones son depósitos(D), extracciones(E), varios (O). Declare tres Queues de cada tipo de operación correspondiente.
A. Inicialmente la gente forma 1 fila, cuando comienza la atención las personas se distribuyen según la operación, sacando un turno (botón “Simular turno”).
B. Modele estructura persona. Debe introducir por una pantalla un DNI, y elegir el tipo de operación, según sea, se encola la persona para ser atendida en la fila correspondiente.
C. Otra función “atender”, ira sacando gente de la fila elegida por orden de llegada.
D. Se deben averiguar cuál es el último número agregado a cierta cola. Ej. Ultimo DNI en Extracción
*/
#include <iostream>
#include <queue>

using namespace std;

// Estructura para almacenar la información de las personas
struct Persona {
    string DNI;
    char operacion;
};

// Función para atender a los clientes
void atender(queue<Persona>& cola) {
    if (!cola.empty()) {
        Persona p = cola.front();
        cout << "Cliente atendido: " << p.DNI << " - Operación: " << p.operacion << endl;
        cola.pop();
    } else {
        cout << "No hay clientes en la cola" << endl;
    }
}

int main() {
    queue<Persona> depositos;
    queue<Persona> extracciones;
    queue<Persona> operaciones_varias;

    Persona p1;
    p1.DNI = "12345678A";
    p1.operacion = 'D';
    depositos.push(p1);

    Persona p2;
    p2.DNI = "23456789B";
    p2.operacion = 'E';
    extracciones.push(p2);

    Persona p3;
    p3.DNI = "34567890C";
    p3.operacion = 'O';
    operaciones_varias.push(p3);

    // Se encola un cliente para ser atendido en la cola correspondiente a la operación que elija
    Persona p4;
    p4.DNI = "45678901D";
    char operacion;
    cout << "Introduzca el DNI del cliente: ";
    cin >> p4.DNI;
    cout << "Introduzca la operación ('D' para depósito, 'E' para extracción, 'O' para operaciones variadas): ";
    cin >> operacion;
    p4.operacion = operacion;

    if (operacion == 'D') {
        depositos.push(p4);
    } else if (operacion == 'E') {
        extracciones.push(p4);
    } else if (operacion == 'O') {
        operaciones_varias.push(p4);
    } else {
        cout << "Operación no válida" << endl;
    }

    // Se atienden los clientes en las diferentes colas
    cout << "Clientes en cola de depositos: " << depositos.size() << endl;
    atender(depositos);

    cout << "Clientes en cola de extracciones: " << extracciones.size() << endl;
    atender(extracciones);

    cout << "Clientes en cola de operaciones varias: " << operaciones_varias.size() << endl;
    atender(operaciones_varias);

    // Se busca el último DNI en cola de extracciones
    if (!extracciones.empty()) {
        cout << "Último DNI en Extracción: " << extracciones.back().DNI << endl;
    } else {
        cout << "No hay clientes en la cola de extracciones" << endl;
    }

    return 0;
}