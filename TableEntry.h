#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    // Constructores
    TableEntry(const std::string& key, const V& value);
    TableEntry(const std::string& key);
    TableEntry();

    // Accesores
    const std::string& getKey() const;
    const V& getValue() const;
    void setValue(const V& value);

    // Operadores
    friend std::ostream& operator<<(std::ostream& os, const TableEntry<V>& entry);
    bool operator==(const TableEntry<V>& other) const;
    bool operator!=(const TableEntry<V>& other) const;

private:
    std::string key;
    V value;
};

#endif // TABLEENTRY_H
