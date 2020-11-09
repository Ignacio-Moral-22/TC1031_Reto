#ifndef reto_parte_3_hpp
#define reto_parte_3_hpp

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "clase_archivo.hpp"
#include "ConexionesComputadoras.hpp"
#include "clase_archivo.hpp"

//Checar anomalias en conexionesSalientes de las IPs
void checarAnomalias(std::set<std::string> ipsUnicas, std::map<std::string, std::string> hosts, std::string val1, std::string val2)
{
    std::map<std::string, std::string>::iterator it = hosts.begin();
    while (it != hosts.end())
    {
        std::string name = it->first;
        std::string ip = it->second;

        std::set<std::string>::iterator it2 = ipsUnicas.begin();
        while (it2 != ipsUnicas.end())
        {
            if((*it2)==ip)
            {
                std::cout << "Esta computadora si se ha conectado con un IP anomalo.\n" <<
                "Se ha conectado con: " << val1 << " y tiene la IP: " << ip << std::endl;
            } else if ((*it2)==ip)
            {
                std::cout << "Esta computadora si se ha conectado con un IP anomalo.\n" <<
                "Se ha conectado con: " << val2 << " y tiene la IP: " << ip << std::endl;
            }
            it2++;
        }

        it++;
    }
    
}

//Guardar vector de Objetos Registros
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

//Solo guarda el set de hostnamedestinos que no sean reto.com o "-"
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
        if(hostNameDestino.erase(0, hostNameDestino.length()-8)!="reto.com" && hndRes!="-")
        {
            hosts.insert(hndRes);
        }
    }

    return hosts;
}

//Guardar vector de Objetos Registros, pero no guarda hostnamesdestino que sean reto.com o "-"
std::vector<class Registros<std::string>> read2()
{
    std::vector<class Registros<std::string>> hosts2;
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
        if(hostNameDestino.erase(0, hostNameDestino.length()-8)!="reto.com" && hndRes!="-")
        {
            Registros<std::string> r(fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hndRes);
            hosts2.push_back(r);
        }
    }
    return hosts2;
}

//Map de IPs Anomalos
std::map<std::string, std::string> getIPAnomalo(std::set<std::string> &hosts, std::vector<class Registros<std::string>> &hosts2, std::string val1, std::string val2)
{
    std::map<std::string, std::string> ipAnomalos;
    for(int i=0; i<hosts2.size(); i++)
    {
         for(auto& e: hosts)
        {
            if(e==hosts2.at(i).destinoHost() && (e==val1 || e==val2))
            {
                ipAnomalos.insert(std::make_pair(e, hosts2.at(i).destinoIP()));
            }
        }
    }

    for(const auto& u: ipAnomalos)
    {
        std::cout << u.first << ": " << u.second << std::endl;
    }

    return ipAnomalos;
}

//Map de string y ConexionesComputadoras
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

    std::map<std::string, ConexionesComputadoras<std::string>>::iterator it = diccionario.begin();
    while (it != diccionario.end())
    {
        std::string ips = it->first;
        int conexiones = it->second.getNumeroConexionesSalientes();
        std::cout << "IP: " << ips << ", Conexiones Salientes: " << conexiones << std::endl;
        it++;
    }
    return diccionario;
}

//Imprime conexiones salientes
void printUniqueIPs(std::map<std::string, ConexionesComputadoras<std::string>> &diccionarios, int numeroIPs, std::map<std::string, std::string> ipAnomalos, std::string val1, std::string val2)
{
    for(int i=0; i<numeroIPs; i++)
    {
        std::string ips;
        std::cout << "Que IP quieres buscar sus conexiones?\n";
        std::cin >> ips;
        std::set<std::string> ipsUnicas;
        std::cout << "El numero de conexiones salientes totales son: " << diccionarios[ips].getNumeroConexionesSalientes() << std::endl;
        for(size_t i=0; i<diccionarios[ips].getNumeroConexionesSalientes(); i++)
        {
            std::string ipUnica;
            ipUnica=diccionarios[ips].getConexionesSalientes();
            ipsUnicas.insert(ipUnica);
        }

        std::set<std::string>::iterator it = ipsUnicas.begin();
        while (it != ipsUnicas.end())
        {
            std::cout << (*it) << " , ";
            it++;
        }
        std::cout << std::endl;

        checarAnomalias(ipsUnicas, ipAnomalos, val1, val2);

    }
}





#endif
