#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h" // ¡¡¡MODIFICAR SEGÚN LA UBICACIÓN!!!

template <typename V>
class HashTable : public Dict<V> {

private:
    // Atributos privados
    int n; // Número de elementos almacenados actualmente en la tabla hash
    int max; // Tamaño de la tabla hash (número total de cubetas)
    ListLinked<TableEntry<V>>* table; // Tabla de cubetas (array de listas enlazadas)

    // Método privado
    int h(std::string key) {
        // Función hash: Calcula el índice basado en la suma de los valores ASCII
        // de los caracteres de la clave y el tamaño total de la tabla.
        int hashValue = 0;
        for (char ch : key) {
            hashValue += static_cast<int>(ch);
        }
        return hashValue % max;
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        // Reserva memoria dinámica para la tabla hash
        table = new ListLinked<TableEntry<V>>[max];
    }

    // Destructor
    ~HashTable() {
        // Libera la memoria dinámica de la tabla
        delete[] table;
    }

    // Método que devuelve el número total de cubetas
    int capacity() {
        return max;
    }

    // Sobrecarga del operador []
    V operator[](std::string key) {
        int index = h(key);
        // Recorre la lista en la posición calculada
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value; // Devuelve el valor si la clave coincide
            }
        }
        throw std::runtime_error("Clave no encontrada"); // Lanza excepción si no se encuentra
    }

    // Sobrecarga del operador << para imprimir la tabla
    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        for (int i = 0; i < ht.max; ++i) {
            out << "Cubeta " << i << ": ";
            for (auto it = ht.table[i].begin(); it != ht.table[i].end(); ++it) {
                out << "[" << it->key << ": " << it->value << "] ";
            }
            out << "\n";
        }
        return out;
    }
};

#endif     
