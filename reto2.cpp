#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include "clase_archivo.hpp"
#include "conexionesComputadora.hpp"
#include "read_csv.hpp"
#include "sorter.hpp"

bool compareIPFuente(Registros<std::string> &a, Registros<std::string> &b){
    return a.fuenteIP()<b.fuenteIP();
};


bool compareIPDestino(Registros<std::string> &a, Registros<std::string> &b){
    return a.destinoIP()<b.destinoIP();
};

int main(){
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    std::vector<class Registros<std::string>> registros2;
    registros2=registros;
    Sorter<Registros<std::string>> organizar;
    organizar.ordenaQuick(registros, &compareIPFuente);
    organizar.ordenaQuick(registros2, &compareIPDestino);
    int i=0;
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    while(i<registros.size()){
        std::string ip, nombre;
        std::stack<std::string> conexionesEntrantes;
        std::queue<std::string> conexionesSalientes;
        ip=registros.at(i).fuenteIP();
        nombre=registros.at(i).fuenteHost();
        while(registros.at(i).fuenteIP()==ip){
            conexionesEntrantes.push(registros2.at(i).fuenteIP());
            conexionesSalientes.push(registros.at(i).destinoIP());
            i++;
        }
        ConexionesComputadoras<std::string> c;
        c.setIP(ip);
        c.setNombre(nombre);
        c.setConexionesEntrantes(conexionesEntrantes);
        c.setConexionesSalientes(conexionesSalientes);
        conexiones.push_back(c);
    }

    for(size_t j=0; j<conexiones.size(); j++){
        conexiones.at(j).printIP();
    }

    return 0;
}