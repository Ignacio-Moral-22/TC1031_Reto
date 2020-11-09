#ifndef reto_parte_3_hpp
#define reto_parte_3_hpp

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "clase_archivo.hpp"
#include "ConexionesComputadoras.hpp"

std::vector<class Registros<std::string>> readRecords2(){
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

std::set<std::string> read()
{
    std::set<std::string> hosts;
    std::ifstream valores("nuevo10.csv");
    std::string fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino, hndRes;
    while (valores.peek()!=EOF)
    {
        std::getline(valores, fecha, ',');
        std::getline(valores, hora, ',');
        std::getline(valores, ipFuente, ',');
        std::getline(valores, puertoFuente, ',');
        std::getline(valores, hostNameFuente, ',');
        std::getline(valores, ipDestino, ',');
        std::getline(valores, puertoDestino, ',');
        std::getline(valores, hostNameDestino, '\n');
        hndRes=hostNameDestino;
        if(hostNameDestino.erase(0, hostNameDestino.length()-8)!="reto.com")
        {
            hosts.insert(hndRes);
        }
    }
    return hosts;
}

std::map<std::string, std::string> read2()
{
    std::map<std::string, std::string> hosts2;
    std::ifstream valores("nuevo10.csv");
    std::string fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino, hndRes;
    while (valores.peek()!=EOF)
    {
        std::getline(valores, fecha, ',');
        std::getline(valores, hora, ',');
        std::getline(valores, ipFuente, ',');
        std::getline(valores, puertoFuente, ',');
        std::getline(valores, hostNameFuente, ',');
        std::getline(valores, ipDestino, ',');
        std::getline(valores, puertoDestino, ',');
        std::getline(valores, hostNameDestino, '\n');
        hndRes=hostNameDestino;
        if(hostNameDestino.erase(0, hostNameDestino.length()-8)!="reto.com")
        {
            hosts2.insert(std::make_pair(hndRes, ipDestino));
        }
    }
    for(auto& a: hosts2)
    {
        std::cout << a.first << "\n\t" << a.second << std::endl;
    }
    return hosts2;
}

std::map<std::string, ConexionesComputadoras<std::string>> diccionarios(std::vector<class ConexionesComputadoras<std::string>> &registros)
{
    std::map<std::string, ConexionesComputadoras<std::string>> diccionario;
    for(int i=0; i<registros.size(); i++)
    {
        if(registros.at(i).getIP()!="-")
        {
            diccionario.insert(std::make_pair(registros.at(i).getIP(), registros.at(i)));
        }
    }

    for(auto& e: diccionario)
    {
        if(e.second.getNumeroConexionesEntrantes()>1)
        {
            std::cout << e.first << "\t" << e.second.getNumeroConexionesEntrantes() << std::endl;
        }
    }
    return diccionario;
}

void printUniqueIPs(std::map<std::string, ConexionesComputadoras<std::string>> &diccionarios, int numeroIPs, std::map<std::string, std::string> hosts)
{
    for(int i=0; i<numeroIPs; i++)
    {
        std::string ips;
        std::cout << "Que IP quieres buscar sus conexiones?\n";
        std::cin >> ips;
        std::set<std::string> ipsUnicas;
        for(int i=0; i<diccionarios[ips].getNumeroConexionesEntrantes(); i++)
        {
            std::string ipUnica;
            ipUnica=diccionarios[ips].getConexionesEntrantes();
            ipsUnicas.insert(ipUnica);
        }
        for(auto&e : ipsUnicas)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;

    }
}




#endif
