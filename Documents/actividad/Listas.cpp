#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = 0;
    }

    void insertarNodo(int valor) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void imprimirNodos() {
        Nodo* actual = cabeza;

        cout << "Datos:" << endl;
        while (actual != 0) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void eliminarNodos(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = 0;
        bool seEliminoAlMenosUno = false;

        while (actual != 0) {
            if (actual->dato == valor) {
                if (anterior == 0) {
                    cabeza = actual->siguiente;
                    delete actual;
                    actual = cabeza;
                } else {
                    anterior->siguiente = actual->siguiente;
                    Nodo* temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                }
                seEliminoAlMenosUno = true;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
    }

    void eliminarNodo(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = 0;
        bool nodoEliminado = false;

        while (actual != 0) {
            if (actual->dato == valor) {
                if (anterior == 0) {
                    cabeza = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
                nodoEliminado = true;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
    }
};

int main() {
    ListaEnlazada lista;

    char opcion;
    int valor;

    do {
        cout << "1) Ingresar dato" << endl;
        cout << "2) Eliminar dato" << endl;
        cout << "3) Mostrar datos" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case '1':
                cout << "Ingrese el dato a ingresar: ";
                cin >> valor;
                lista.insertarNodo(valor);
                break;
            case '2':
                cout << "Ingrese el dato a eliminar: ";
                cin >> valor;
                lista.eliminarNodo(valor);
                break;
            case '3':
                lista.imprimirNodos();
                break;
            case '4':
                break;

        }
    } while (opcion != '4');

    return 0;
}
