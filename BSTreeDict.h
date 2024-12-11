#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

// Clase genérica BSTreeDict que implementa un diccionario basado en ABB
template <typename V>
class BSTreeDict : public Dict<V> {

private:
    // Atributos
    BSTree<TableEntry<V> >* tree; // ABB con elementos tipo TableEntry<V>

public:
    // Métodos

    // Constructor: inicializa el ABB como vacío
    BSTreeDict() : tree(new BSTree<TableEntry<V> >()) {}

    // Destructor: libera la memoria ocupada por el ABB
    ~BSTreeDict() {
        delete tree;
    }

    // Sobrecarga del operador << para imprimir el contenido del diccionario
    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& bs) {
        out << *(bs.tree); // Asume que BSTree tiene sobrecargado el operador <<
        return out;
    }

    // Sobrecarga del operador [] para buscar elementos por clave
    V operator[](std::string key) {
        TableEntry<V> entry(key); // Crea una entrada temporal con la clave
        TableEntry<V>* result = tree->search(entry);
        if (result == nullptr) {
            throw std::out_of_range("Clave no encontrada en el diccionario.");
        }
        return result->getValue(); // Devuelve el valor asociado a la clave
    }

    // Implementar otros métodos heredados de Dict<V> si es necesario

};

#endif

