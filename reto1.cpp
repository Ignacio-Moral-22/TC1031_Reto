#include "read_csv.hpp"
#include "clase_archivo.hpp"
#include "sorter.hpp"
#include <vector>
#include <iostream>
#include <string>
/*
Descripcion Breve...
Ignacio Joaquin Moral
A01028470
Fecha de creacion: 17 de septiembre de 2020
Fecha de modificacion final: 24 de septiembre de 2020
*/

bool compareHostNameFuente(Registros<std::string> &a, Registros<std::string> &b){
    return a.fuenteHost()<b.fuenteHost();
}

int main(){
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    int dia2;
    dia2=segundoDia(registros);
    std::cout << dia2 << std::endl;
    Sorter<Registros<std::string>> organizar;
    organizar.selectionSort(registros, &compareHostNameFuente);
    countNames(registros);


    return 0;
}
