#ifndef reto_parte_2_hpp
#define reto_parte_2_hpp
#include <vector>
#include <string>
#include <iostream>
#include "busqueda.hpp"
#include "ConexionesComputadoras.hpp"
using std::cout;
using std::string;
using std::vector;
using std::endl;

void valores(vector<class ConexionesComputadoras<string>> &registros, int i){
    cout << "La direccion IP es " << registros.at(i).getIP() << endl;
    cout << "El nombre de la computadora es: " << registros.at(i).getNombre() << endl;
    cout << "La computadora tiene " << registros.at(i).getNumeroConexionesEntrantes() << " conexiones entrantes." << endl;
    cout << "La conexion entrante mas reciente es: " << registros.at(i).getConexionesEntrantes() << endl;
    cout << "La computadora tiene " << registros.at(i).getNumeroConexionesSalientes() << " conexiones salientes." << endl;
    cout << "La conexion saliente mas reciente es: " << registros.at(i).getConexionesSalientes() << endl;
}

void busquedaDireccion(vector<class ConexionesComputadoras<string>> &registros, string add){
    string ipCompania = registros.at(registros.size()-1).getIP();
    ipCompania.erase(10,ipCompania.length()-10);
    ipCompania.append(".");
    ipCompania.append(add);
    
    vector<string> direccionesIPs;
    for(int i=0;i<registros.size();i++){
        direccionesIPs.push_back(registros.at(i).getIP());
    }

    int resultado;
    resultado=busquedaBinaria<string>(0, registros.size()-1, ipCompania, direccionesIPs);
    if(resultado==-1){
        cout << "La direccion IP no existe en esta compania" << endl;
    } else {
        valores(registros, resultado);
    }
}


#endif
