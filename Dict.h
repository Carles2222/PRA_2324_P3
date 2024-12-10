#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept> // Para std::runtime_error

template <typename V>
class Dict {
public:
    // Destructor virtual puro para asegurar que la clase sea abstracta
    virtual ~Dict() = default;

    // Método virtual puro para insertar un par clave-valor
    virtual void insert(std::string key, V value) = 0;

    // Método virtual puro para buscar un valor por clave
    virtual V search(std::string key) = 0;

    // Método virtual puro para eliminar un par clave-valor
    virtual V remove(std::string key) = 0;

    // Método virtual puro para obtener el número de elementos
    virtual int entries() const = 0;
};

#endif

