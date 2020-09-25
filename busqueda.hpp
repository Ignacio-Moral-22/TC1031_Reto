#include <vector>
#include "clase_archivo.hpp"
template <typename T>
int busquedaBinariaHostNameFuente(int inicio, int final, T valor, std::vector<class Registros<T>> &valores){
    if(final>=inicio){
        int i=inicio + (final-inicio)/2;
        if(valores.at(i).fuenteHost()==valor){
            return i;
        } 
        if (valores.at(i).fuenteHost()>valor){
            return busquedaBinariaHostNameFuente(inicio, i-1, valor, valores);
        }
        return busquedaBinariaHostNameFuente(i+1, final, valor, valores);
    }
    return -1;
}