#ifndef generar_conexiones_3_hpp
#define generar_conexiones_3_hpp
#include <stack>
#include <queue>
#include <vector>
#include "clase_archivo.hpp"
#include "ConexionesComputadoras.hpp"
#include "sorter.hpp"
#include "reto_parte_3.hpp"

//Similar a parte 2, guardar Conexiones

bool compareIPFuente(Registros<std::string> &a, Registros<std::string> &b)
{
    return a.fuenteIP()>b.fuenteIP();
};

bool compareIPDestino(Registros<std::string> &a, Registros<std::string> &b)
{
    return a.destinoIP()>b.destinoIP();
};

std::vector<class ConexionesComputadoras<std::string>> genera_conexiones()
{
    std::vector<class Registros<std::string>> registros;
    registros=readRecords2();
    std::vector<class Registros<std::string>> registros2;
    registros2=registros;
    Sorter<Registros<std::string>> organizar;
    organizar.ordenaQuick(registros, &compareIPFuente);
    organizar.ordenaQuick(registros2, &compareIPDestino);
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    size_t i=0;

    while(i<registros.size())
    {
        std::string ip, nombre;
        std::stack<std::string> conexionesEntrantes;
        std::queue<std::string> conexionesSalientes;
        ip=registros.at(i).fuenteIP();
        nombre=registros.at(i).fuenteHost();

        while(i<registros.size() && registros.at(i).fuenteIP()==ip)
        {
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
    return conexiones;
}

#endif