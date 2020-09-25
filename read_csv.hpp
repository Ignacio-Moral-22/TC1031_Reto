#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "clase_archivo.hpp"
#include "busqueda.hpp"
using namespace std;

vector<class Registros<string>> readRecords(){
    ifstream valores("equipo10.csv");
    string fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino;
    vector<class Registros<string>> registros;
    while (valores.peek()!=EOF){
        getline(valores, fecha, ',');
        getline(valores, hora, ',');
        getline(valores, ipFuente, ',');
        getline(valores, puertoFuente, ',');
        getline(valores, hostNameFuente, ',');
        getline(valores, ipDestino, ',');
        getline(valores, puertoDestino, ',');
        getline(valores, hostNameDestino, '\n');
        Registros<string> r(fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino);
        registros.push_back(r);
    }
    
    int count=0;
    for(int i=0; i<registros.size(); i++){
        count+=1;
    }

    cout << "El archivo tiene " << count << " registros." << endl;
    valores.close();
    return registros;
}

int segundoDia(vector<class Registros<string>> &registros){
    string dia1, dia2 = "";
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
    cout<<"El segundo dia es " << dia2 << endl;
    return contar_dia_2;
}

void countNames(vector<class Registros<string>> &registros){
    int nameCount;
    cout<<"How many names do you wish to create?" << endl;
    cin >> nameCount;
    string names[nameCount];
    for(int i=0; i<nameCount; i++){
        cout << "Write a name." << endl;
        cin >> names[i];
        names[i].append(".reto.com");
    };
    int posiciones[nameCount];
    for(int j=0; j<nameCount; j++){
        posiciones[j]=busquedaBinariaHostNameFuente<string>(0, registros.size(), names[j], registros);
        cout<<posiciones[j]<<endl;
    };


}