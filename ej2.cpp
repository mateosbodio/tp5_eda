/*
2. Se tienen pilaA, pilaB, pilaC con enteros, y los procedimientos o funciones son:
a. InvierteConAux, Dada una Pila A con números, una Pila B y una Pila C vacías, pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A. (Se permite utilizar la pila C como auxiliar)
b. InvierteSinAux, que dada una PilaA, una variable X y una Pila Vacía B. Pasar los elementos de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden (original) en pilaA.
c. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo otro “Y”

*/
void InvierteConAux(Pila& pilaA, Pila& pilaB, Pila& pilaC) {
    if (pilaA.empty()) return;
    
    int temp = pilaA.top();
    pilaA.pop();
    
    InvierteConAux(pilaA, pilaB, pilaC);
    
    pilaC.push(temp);
    
    while (!pilaC.empty()) {
        pilaB.push(pilaC.top());
        pilaC.pop();
    }
}
void InvierteSinAux(Pila& pilaA, int x, Pila& pilaB) {
    if (pilaA.empty()) return;
    
    int temp = pilaA.top();
    pilaA.pop();
    
    InvierteSinAux(pilaA, x, pilaB);
    
    if (temp == x) {
        pilaB.push(y);
    } else {
        pilaB.push(temp);
    }
}
bool BuscarReemplazar(Pila& pilaA, int x, int y) {
    if (pilaA.empty()) return false;
    
    int temp = pilaA.top();
    pilaA.pop();
    
    if (temp == x) {
        pilaA.push(y);
        return true;
    } else {
        pilaA.push(temp);
        return BuscarReemplazar(pilaA, x, y);
    }
}