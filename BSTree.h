#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class ArbolBinarioBusqueda {
private:
    BSNode<T>* raiz; // Puntero a la raíz del árbol
    int tamano;      // Número de elementos en el árbol

    // Métodos privados auxiliares
    void destruir(BSNode<T>* nodo);
    BSNode<T>* insertar(BSNode<T>* nodo, const T& valor);
    BSNode<T>* eliminar(BSNode<T>* nodo, const T& valor);
    BSNode<T>* encontrarMinimo(BSNode<T>* nodo) const;
    void recorridoEnOrden(BSNode<T>* nodo, std::ostream& os) const;

public:
    // Constructor y destructor
    ArbolBinarioBusqueda();
    ~ArbolBinarioBusqueda();

    // Métodos públicos
    int obtenerTamano() const;
    bool estaVacio() const;
    void insertar(const T& valor);
    void eliminar(const T& valor);
    bool buscar(const T& valor) const;
    void imprimirEnOrden(std::ostream& os = std::cout) const;
};

// Implementación de los métodos
template <typename T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda() : raiz(nullptr), tamano(0) {}

template <typename T>
ArbolBinarioBusqueda<T>::~ArbolBinarioBusqueda() {
    destruir(raiz);
}

template <typename T>
void ArbolBinarioBusqueda<T>::destruir(BSNode<T>* nodo) {
    if (nodo) {
        destruir(nodo->izquierdo);
        destruir(nodo->derecho);
        delete nodo;
    }
}

template <typename T>
int ArbolBinarioBusqueda<T>::obtenerTamano() const {
    return tamano;
}

template <typename T>
bool ArbolBinarioBusqueda<T>::estaVacio() const {
    return tamano == 0;
}

template <typename T>
void ArbolBinarioBusqueda<T>::insertar(const T& valor) {
    raiz = insertar(raiz, valor);
    tamano++;
}

template <typename T>
BSNode<T>* ArbolBinarioBusqueda<T>::insertar(BSNode<T>* nodo, const T& valor) {
    if (!nodo) return new BSNode<T>(valor);
    if (valor < nodo->dato)
        nodo->izquierdo = insertar(nodo->izquierdo, valor);
    else if (valor > nodo->dato)
        nodo->derecho = insertar(nodo->derecho, valor);
    return nodo;
}

template <typename T>
void ArbolBinarioBusqueda<T>::eliminar(const T& valor) {
    raiz = eliminar(raiz, valor);
    tamano--;
}

template <typename T>
BSNode<T>* ArbolBinarioBusqueda<T>::eliminar(BSNode<T>* nodo, const T& valor) {
    if (!nodo) return nullptr;
    if (valor < nodo->dato)
        nodo->izquierdo = eliminar(nodo->izquierdo, valor);
    else if (valor > nodo->dato)
        nodo->derecho = eliminar(nodo->derecho, valor);
    else {
        if (!nodo->izquierdo) {
            BSNode<T>* temporal = nodo->derecho;
            delete nodo;
            return temporal;
        } else if (!nodo->derecho) {
            BSNode<T>* temporal = nodo->izquierdo;
            delete nodo;
            return temporal;
        }
        BSNode<T>* temporal = encontrarMinimo(nodo->derecho);
        nodo->dato = temporal->dato;
        nodo->derecho = eliminar(nodo->derecho, temporal->dato);
    }
    return nodo;
}

template <typename T>
BSNode<T>* ArbolBinarioBusqueda<T>::encontrarMinimo(BSNode<T>* nodo) const {
    while (nodo && nodo->izquierdo)
        nodo = nodo->izquierdo;
    return nodo;
}

template <typename T>
bool ArbolBinarioBusqueda<T>::buscar(const T& valor) const {
    BSNode<T>* actual = raiz;
    while (actual) {
        if (valor == actual->dato)
            return true;
        else if (valor < actual->dato)
            actual = actual->izquierdo;
        else
            actual = actual->derecho;
    }
    return false;
}

template <typename T>
void ArbolBinarioBusqueda<T>::imprimirEnOrden(std::ostream& os) const {
    recorridoEnOrden(raiz, os);
    os << std::endl;
}

template <typename T>
void ArbolBinarioBusqueda<T>::recorridoEnOrden(BSNode<T>* nodo, std::ostream& os) const {
    if (nodo) {
        recorridoEnOrden(nodo->izquierdo, os);
        os << nodo->dato << " ";
        recorridoEnOrden(nodo->derecho, os);
    }
}

#endif

