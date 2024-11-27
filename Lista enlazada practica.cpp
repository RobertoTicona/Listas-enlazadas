#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Nodo {
    string dato;      // Nombre del puesto
    Nodo* siguiente;  // Apunta al siguiente nodo
};

// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, string);
void mostrarLista(Nodo *);

Nodo* lista = NULL;

int main() {
    menu();
    system("pause");
    return 0;
}

void menu() {
    int opcion;
    string dato;

    do {
        cout << "\t. REGISTRO DE PUESTOS EN EL MERCADO: " << endl;
        cout << "1. Insertar puestos del mercado Bellavista a la lista\n";
        cout << "2. Mostrar los puestos del mercado Bellavista de la lista\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite el nombre del puesto: ";
                cin.ignore(); // Para ignorar el salto de línea restante
                getline(cin, dato);  // Capturamos el nombre completo
                insertarLista(lista, dato);
                cout << "\n";
                system("pause");
                break;
            case 2:
                mostrarLista(lista);
                cout << "\n";
                system("pause");
                break;
        }
        system("cls");

    } while (opcion != 3);
}

void insertarLista(Nodo*& lista, string n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo* aux1 = lista;
    Nodo* aux2 = NULL;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;

    cout << "\tPuesto '" << n << "' insertado a lista correctamente" << endl;
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = lista;

    while (actual != NULL) {
        cout << actual->dato << " -> ";  // Mostramos el nombre del puesto
        actual = actual->siguiente;      // Avanzamos al siguiente nodo
    }
    cout << "NULL" << endl;  // Indicamos el fin de la lista
}

