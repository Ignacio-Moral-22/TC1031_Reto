#include <vector>
#include "clase_archivo.hpp"
template <typename T>
int busqueda_binaria(int inicio, int final, T valor, std::vector<class Registros<T>> &registros){
    int i=(final+inicio)/2;
    if(registros.at(i).fuenteHost()==valor){
        return i;
    } else if (registros.at(i).fuenteHost()<valor){
        return busqueda_binaria(i, final, valor, registros);
    } else {
        return busqueda_binaria(inicio, i, valor, registros);
    }
    return -1;
}