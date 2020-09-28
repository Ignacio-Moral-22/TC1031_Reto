#include <vector>
#include "clase_archivo.hpp"
template <typename T>
int busquedaBinaria(int inicio, int final, T valor, std::vector<T> &valores){
    if(final>=inicio){
        int i=inicio + (final-inicio)/2;
        if(valores.at(i)==valor){
            return i;
        } 
        if (valores.at(i)>valor){
            return busquedaBinaria(inicio, i-1, valor, valores);
        }
        return busquedaBinaria(i+1, final, valor, valores);
    }
    return -1;
}
