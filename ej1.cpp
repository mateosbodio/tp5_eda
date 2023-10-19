/*
1. En el menú principal, se cuenta con las siguientes pilas: Tubo1, Tubo2, Tubo3.
a. cargaTubo, que permita introducir datos en el cada uno de los tubos
b. pasarPelota, pasa todos los elementos de Tubo1 a Tubo2
c. hayColor, que recibe un color “rojo” y determina si está en la Tubo1, todos los
elementos deben quedar nuevamente en Tubo1
d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás
*/
#include <iostream>
#include <stack>
#include <string>

void cargaTubo(std::stack<std::string>& tubo) {
    std::string color;
    while (true) {
        std::cout << "Ingrese un color o escriba 'salir' para terminar: ";
        std::cin >> color;
        if (color == "salir") {
            break;
        }
        tubo.push(color);
    }
}

void pasarPelota(std::stack<std::string>& tubo1, std::stack<std::string>& tubo2) {
    while (!tubo1.empty()) {
        tubo2.push(tubo1.top());
        tubo1.pop();
    }
}

bool hayColor(std::stack<std::string>& tubo1, const std::string& color) {
    while (!tubo1.empty()) {
        if (tubo1.top() == color) {
            return true;
        }
        tubo1.pop();
    }
    return false;
}

void colorear(std::stack<std::string>& tubo1, std::stack<std::string>& tubo2, std::stack<std::string>& tubo3) {
    while (!tubo1.empty()) {
        std::string color = tubo1.top();
        tubo1.pop();
        if (color == "rojo") {
            tubo2.push(color);
        } else {
            tubo3.push(color);
        }
    }
}

int main() {
    std::stack<std::string> tubo1;
    std::stack<std::string> tubo2;
    std::stack<std::string> tubo3;

    int opcion;
    while (true) {
        std::cout << "Menu principal:" << std::endl;
        std::cout << "1. Cargar tubo" << std::endl;
        std::cout << "2. Pasar pelota" << std::endl;
        std::cout << "3. Hay color" << std::endl;
        std::cout << "4. Colorear" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cargaTubo(tubo1);
                break;
            case 2:
                pasarPelota(tubo1, tubo2);
                break;
            case 3: {
                std::string color;
                std::cout << "Ingrese un color para buscar: ";
                std::cin >> color;
                if (hayColor(tubo1, color)) {
                    std::cout << "El color " << color << " esta en el tubo." << std::endl;
                } else {
                    std::cout << "El color " << color << " no esta en el tubo." << std::endl;
                }
                break;
            }
            case 4:
                colorear(tubo1, tubo2, tubo3);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Opcion invalida." << std::endl;
        }
    }
}