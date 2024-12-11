#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    // Constructores
    TableEntry(const std::string& key, const V& value) : key(key), value(value) {}
    TableEntry(const std::string& key) : key(key), value() {}
    TableEntry() : key(""), value() {}

    // Accesores
    const std::string& getKey() const { return key; }
    const V& getValue() const { return value; }
    void setValue(const V& value) { this->value = value; }

    // Operadores
    friend std::ostream& operator<<(std::ostream& os, const TableEntry<V>& entry) {
        os << "[" << entry.key << ": " << entry.value << "]";
        return os;
    }

    bool operator==(const TableEntry<V>& other) const {
        return key == other.key && value == other.value;
    }

    bool operator!=(const TableEntry<V>& other) const {
        return !(*this == other);
    }

    // Sobrecarga de operadores < y >
    friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key < te2.key;
    }

    friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key > te2.key;
    }

private:
    std::string key;
    V value;
};

#endif // TABLEENTRY_H

