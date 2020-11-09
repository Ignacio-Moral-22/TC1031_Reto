#ifndef read_csv_2_hpp
#define read_csv_2_hpp
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "clase_archivo.hpp"

std::vector<class Registros<std::string>> readRecords(){
    std::ifstream valores("nuevo10.csv");
    std::string fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino;
    std::vector<class Registros<std::string>> registros;
    while (valores.peek()!=EOF){
        std::getline(valores, fecha, ',');
        std::getline(valores, hora, ',');
        std::getline(valores, ipFuente, ',');
        std::getline(valores, puertoFuente, ',');
        std::getline(valores, hostNameFuente, ',');
        std::getline(valores, ipDestino, ',');
        std::getline(valores, puertoDestino, ',');
        std::getline(valores, hostNameDestino, '\n');
        Registros<std::string> r(fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino);
        registros.push_back(r);
    }

    valores.close();
    return registros;
};

#endif