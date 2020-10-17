#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include "clase_archivo.hpp"
#include "ConexionesComputadoras.hpp"
#include "read_csv.hpp"
#include "sorter.hpp"
#include "reto_parte_2.hpp"
/*
Para esta parte del programa, se me pidio generar una clase llamada ConexionesComputadoras
que tenga IP, Nombre, conexionesEntrantes, y conexionesSalientes
conexionesEntrantes es una estructura lineal que permita ver de atras para adelante
conexionesSalientes igualmente es una estructura lineal que se pueda leer de forma lineal


Ignacio Joaquin Moral
A01028470
Fecha de Inicio: 15 de octubre de 2020
Ultimo Cambio: 16 de octubre de 2020
*/
bool compareIPFuente(Registros<std::string> &a, Registros<std::string> &b){
    return a.fuenteIP()<b.fuenteIP();
};

bool compareIPDestino(Registros<std::string> &a, Registros<std::string> &b){
    return a.destinoIP()<b.destinoIP();
};

int main(){
    //Genera 2 vectores de la clase Registros, de la parte 1, 
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    std::vector<class Registros<std::string>> registros2;
    registros2=registros;
    Sorter<Registros<std::string>> organizar;
    organizar.ordenaQuick(registros, &compareIPFuente);
    organizar.ordenaQuick(registros2, &compareIPDestino);
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    size_t i=0;

    //Esta funcion guarda todos los posibles objetos de la clase ConexionesComputadoras
    //en un vector para poder acceder a estos con mayor facilidad
    while(i<registros.size()){
        std::string ip, nombre;
        std::stack<std::string> conexionesEntrantes;
        std::queue<std::string> conexionesSalientes;
        ip=registros.at(i).fuenteIP();
        nombre=registros.at(i).fuenteHost();

        //Mientras el IP en el vector siga siendo el mismo, se sigue
        //avanzando, y agregando las conexiones entrantes y salientes
        //a un stack y un queue, respectivamente
        while(i<registros.size() && registros.at(i).fuenteIP()==ip){
            conexionesEntrantes.push(registros2.at(i).fuenteIP());
            conexionesSalientes.push(registros.at(i).destinoIP());
            i++;
        }
        //Una vez que se hayan guardado todas las conexiones entrantes y salientes,
        //se genera un objeto de ConexionesComputadoras, se guardan los datos, y
        //se guardan en un vector de clases
        ConexionesComputadoras<std::string> c;
        c.setIP(ip);
        c.setNombre(nombre);
        c.setConexionesEntrantes(conexionesEntrantes);
        c.setConexionesSalientes(conexionesSalientes);
        conexiones.push_back(c);
    }

    //Permite al usuario ingresar un numero del 1 al 150 que se buscara en los registros
    std::string add;
    std::cout << "Dame un numero del 1 al 150 para buscar sus conexiones." << std::endl;
    std::getline(std::cin, add);
    busquedaDireccion(conexiones, add);
    return 0;
}