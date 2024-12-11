# Makefile para generar bin/testHashTable

# Regla para generar el binario de prueba bin/testHashTable
bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
mkdir -p bin
g++ -o bin/testHashTable testHashTable.cpp

# Regla para generar el binario de prueba bin/testTableEntry
bin/testTableEntry: testTableEntry.cpp TableEntry.h
mkdir -p bin
g++ -o bin/testTableEntry testTableEntry.cpp

# Limpiar
clean:
rm -rf *.o *.gch bin

