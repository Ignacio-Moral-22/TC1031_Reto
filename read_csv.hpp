#ifndef read_csv_hpp
#define read_csv_hpp
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "clase_archivo.hpp"
#include "busqueda.hpp"

std::vector<class Registros<std::string>> readRecords(){
    std::ifstream valores("equipo10.csv");
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
    
    int count=0;
    for(int i=0; i<registros.size(); i++){
        count+=1;
    }

    std::cout << "El archivo tiene " << count << " registros." << std::endl;
    valores.close();
    return registros;
};

int segundoDia(std::vector<class Registros<std::string>> &registros){
    std::string dia1, dia2 = "";
    int contador_iterativo = 0;
    int contar_dia_2 = 0;
    dia1=registros.at(contador_iterativo).date();
    while (registros.at(contador_iterativo).date()==dia1){
        contador_iterativo++;
    }

    dia2=registros.at(contador_iterativo).date();
    while(registros.at(contador_iterativo).date()==dia2){
        contar_dia_2++;
        contador_iterativo++;
    }
    std::cout<<"El segundo dia es " << dia2 << std::endl;
    return contar_dia_2;
};

void countNames(std::vector<class Registros<std::string>> &registros){
    int nameCount;
    std::cout<<"Cuantos nombres quieres buscar?" << std::endl;
    std::cin >> nameCount;
    std::string names[nameCount], name[nameCount];
    for(int i=0; i<nameCount; i++){
        std::cout << "Escribe el nombre en minusculas" << std::endl;
        std::cin >> name[i];
        names[i]=name[i];
        names[i].append(".reto.com");
    };

    std::vector<std::string> nombres;
    for(int i=0; i<registros.size(); i++){
        std::string hostDestino = registros.at(i).fuenteHost();
        nombres.push_back(hostDestino);
    }

    int posiciones[nameCount];
    for(int j=0; j<nameCount; j++){
        posiciones[j]=busquedaBinaria<std::string>(0, nombres.size()-1, names[j], nombres);
        if(posiciones[j]==-1){
            std::cout << name[j] << " no es un empleado de la empresa." << std::endl;
        } else {
            std::cout << name[j] << " si trabaja en la empresa." << std::endl;
        }
    };

};

void direccionIP(std::vector<class Registros<std::string>> &registros){
    std::string ipCompania = registros.at(registros.size()-1).fuenteIP();
    ipCompania.erase(10,ipCompania.length()-10);
    ipCompania.append(".0");
    std::cout << "La direccion IP de la compania es " << ipCompania << std::endl;
}

void correos(std::vector<class Registros<std::string>> &registros){
    int contarCorreos;
    std::cout<<"Cuantos correos quieres buscar?" << std::endl;
    std::cin >> contarCorreos;
    std::string correos[contarCorreos];
    for(int i=0; i<contarCorreos; i++){
        std::cout << "Escribe el nombre en minusculas" << std::endl;
        std::cin >> correos[i];
        correos[i].append(".com");
    };

    std::vector<std::string> hostNames;
    for(int i=0; i<registros.size(); i++){
        std::string hostDestino = registros.at(i).destinoHost();
        hostNames.push_back(hostDestino);
    }

    int posiciones[contarCorreos];
    for(int j=0; j<contarCorreos; j++){
        posiciones[j]=busquedaBinaria<std::string>(0, hostNames.size()-1, correos[j], hostNames);
        if(posiciones[j]==-1){
            std::cout << correos[j] << " no es un correo que se usa en la empresa." << std::endl;
        } else {
            std::cout << correos[j] << " si es un correo que se usa en la empresa." << std::endl;
        }
    };
}

void countPuertos(std::vector<class Registros<std::string>> &registros){
    std::vector<std::string> puertos;
    int check;
    for(int i=0; i<registros.size(); i++){
        check=busquedaBinaria(0, puertos.size()-1, registros.at(i).destinoPuerto(), puertos);
        if(check==-1){
            puertos.push_back(registros.at(i).destinoPuerto());
        }
    }
    for(int j=0; j<puertos.size(); j++){
        std::cout << puertos.at(j) << std::endl;
    }
}

#endif