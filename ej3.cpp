/*
3. Suponga que administra un estacionamiento en forma de callejón(pila), cuenta con Cochera1, Cochera2 para 10 autos cada una, ambas solamente tienen una puerta de entrada/salida, y que el valor hora es $100- Se diseña una estructura auto con los datos: placa, propietario, y hora de entrada.
A- Si desea estacionar un auto en Cochera1 o Cochera2, el sistema solicita sus datos, y agrega.
B- Habrá un procedimiento para mostrar las cocheras por orden de salida de los vehículos.
*/
#include <bits/stdc++.h>
using namespace std;

// Estructura Auto
struct Auto {
    string placa;
    string propietario;
    int hora_entrada;
};

// Funcion para agregar auto a las cocheras
void agregarAuto(stack<Auto> &cochera, Auto &autoAgregar) {
    if (cochera.size() < 10) {
        cochera.push(autoAgregar);
        cout << "Auto estacionado exitosamente en Cochera1 o Cochera2" << endl;
    } else {
        cout << "Cochera llena" << endl;
    }
}

// Funcion para mostrar las cocheras por orden de salida de los vehiculos
void mostrarCocheras(stack<Auto> &cochera) {
    stack<Auto> cocheraAux;
    while (!cochera.empty()) {
        cocheraAux.push(cochera.top());
        cout << "Placa: " << cochera.top().placa << " - Propietario: " << cochera.top().propietario << " - Hora de entrada: " << cochera.top().hora_entrada << endl;
        cochera.pop();
    }
    while (!cocheraAux.empty()) {
        cochera.push(cocheraAux.top());
        cocheraAux.pop();
    }
}

int main() {
    // Pilas para simular las cocheras
    stack<Auto> cochera1;
    stack<Auto> cochera2;

    // Ingrese sus datos de autos
    Auto auto1 = {"AAA111", "Juan Pérez", 15};
    Auto auto2 = {"BBB222", "María Rodríguez", 16};

    // Estacionar autos en las cocheras
    agregarAuto(cochera1, auto1);
    agregarAuto(cochera2, auto2);

    // Mostrar las cocheras por orden de salida de los vehiculos
    mostrarCocheras(cochera1);
    mostrarCocheras(cochera2);

    return 0;
}