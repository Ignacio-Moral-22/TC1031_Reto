#include "read_csv.hpp"
#include "clase_archivo.hpp"
#include "sorter.hpp"
#include <vector>
#include <iostream>
#include <string>
/*
Para esta actividad, se nos encargó de generar un programa que leyera una carga de archivos, 
y que pudiera responder ciertas preguntas, además de que implementamos métodos de búsqueda 
y ordenamiento para poder manipular el archivo.

Para poder resolver este avance del reto, primero leímos el archivo, 
y guardamos los valores en una clase llamada Registros. 
Esta clase de Registros era estilo template, para que podamos utilizar 
el estilo de variable que más creamos conveniente. En este caso, decidimos utilizar std::string, 
pues así permite guardar tanto variables numéricas como de texto. Luego, hicimos un vector de clases, 
para poder guardar y organizar los valores a nuestro parecer. Ya que teníamos el vector, 
pudimos responder las diversas preguntas que se nos hizo.

Ignacio Joaquin Moral
A01028470
Fecha de creacion: 17 de septiembre de 2020
Fecha de modificacion final: 27 de septiembre de 2020
*/

bool compareHostNameFuente(Registros<std::string> &a, Registros<std::string> &b){
    return a.fuenteHost()<b.fuenteHost();
};

bool compareIPFuente(Registros<std::string> &a, Registros<std::string> &b){
    return a.fuenteIP()<b.fuenteIP();
};

bool comparePuertoDestino(Registros<std::string> &a, Registros<std::string> &b){
    return a.destinoPuerto()<b.destinoPuerto();
};

bool compareHostNameDestino(Registros<std::string> &a, Registros<std::string> &b){
    return a.destinoHost()<b.destinoHost();
};



int main(){
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    int dia2;
    dia2=segundoDia(registros);
    std::cout << "Hay " << dia2 << " registros en el segundo dia." << std::endl;
    Sorter<Registros<std::string>> organizar;
    organizar.ordenaQuick(registros, &compareHostNameFuente);
    countNames(registros);
    organizar.ordenaQuick(registros, &compareIPFuente);
    direccionIP(registros);
    organizar.ordenaQuick(registros, &compareHostNameDestino);
    correos(registros);

    organizar.ordenaQuick(registros, &comparePuertoDestino);
    countPuertos(registros);

    return 0;
}
