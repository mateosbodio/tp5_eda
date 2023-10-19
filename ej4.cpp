/*
4. En el programa trabajamos ahora con objetos de la clase Queue,
a. Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
b. Utilizando las operaciones de pila y de Fila, COPIE el contenido de una pila P, a una Fila C, de tal manera que el primer elemento de la Fila será el elemento “F” que se encuentra en el fondo de la pila, el segundo de la Fila el que está apilado sobre “F”, y así siguiendo. De esta forma el elemento del tope de la pila quedará en el último lugar de la Fila. (Para resolver este ejercicio, use pila auxiliar)
c. Ahora queremos buscar si el número entero X determinar está en la Fila A. La Fila A deberá quedar en su estado original al finalizar el algoritmo.
d. Además de la Fila A cree la fila B, vacíe la fila A y cargue A y B con elementos ordenados, realice un algoritmo que inserte los elementos de la fila A y B en otra fila C de manera tal que queden ordenados.
e. Dada una fila C que contiene elementos repetidos consecutivos. Formar otra con los elementos de la fila dada eliminando los repetidos.
*/
#include <bits/stdc++.h>
using namespace std;

void invertirFila(queue<int> &A) {
    queue<int> aux;

    while (!A.empty()) {
        aux.push(A.front());
        A.pop();
    }

    while (!aux.empty()) {
        A.push(aux.front());
        aux.pop();
    }
}

int main() {
    queue<int> A = {1, 2, 3, 4, 5};
    queue<int> A_inv;

    A_inv = A;
    invertirFila(A_inv);

    while (!A.empty()) {
        cout << A.front() << " ";
        A.pop();
    }
    cout << endl;

    while (!A_inv.empty()) {
        cout << A_inv.front() << " ";
        A_inv.pop();
    }
    cout << endl;

    return 0;
}
void copiarPilaFila(stack<int> &P, queue<int> &C) {
    stack<int> auxP;
    queue<int> auxC;

    while (!P.empty()) {
        auxP.push(P.top());
        P.pop();
    }

    while (!auxP.empty()) {
        C.push(auxP.top());
        auxP.pop();
    }
}
bool buscarElemento(queue<int> &A, int X) {
    set<int> valores;

    while (!A.empty()) {
        valores.insert(A.front());
        A.pop();
    }

    bool encontrado = valores.find(X) != valores.end();

    while (!valores.empty()) {
        A.push(valores.begin()->second);
        valores.erase(valores.begin());
    }

    return encontrado;
}

void mezclarFilas(queue<int> &A, queue<int> &B, queue<int> &C) {
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    while (!A.empty()) {
        maxHeap.push(A.front());
        A.pop();
    }

    while (!B.empty()) {
        maxHeap.push(B.front());
        B.pop();
    }

    while (!maxHeap.empty()) {
        C.push(maxHeap.top());
        maxHeap.pop();
    }
}
void eliminarRepetidos(queue<int> &C) {
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    int anterior = INT_MIN;

    while (!C.empty()) {
        int actual = C.front();
        C.pop();

        if (actual != anterior) {
            maxHeap.push(actual);
        }

        anterior = actual;
    }

    while (!maxHeap.empty()) {
        C.push(maxHeap.top());
        maxHeap.pop();
    }
}