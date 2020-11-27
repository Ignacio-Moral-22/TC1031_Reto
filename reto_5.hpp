#ifndef RETO_5_HPP
#define RETO_5_HPP
#include <vector>
#include "graph.hpp"
#include "clase_archivo.hpp"
#include "read_csv_2.hpp"
Graph<std::string> checkGraphs(std::string ip, std::vector<int> &idx, std::string date, int index)
{
    std::vector<class Registros<std::string>> registros;
    registros = readRecords();
    Graph<std::string> internoDia1;
    std::vector<int> vecinosSalientes, vecinosEntrantes;
    int first = internoDia1.add_node(ip);
    idx.push_back(first);
    int i=0;
    while(i<registros.size())
    {
        if (registros.at(i).date() != date)
        {
            i++;
        } else
        {
            while(registros.at(i).date()==date)
            {
                if(registros.at(i).fuenteIP()==ip)
                {
                    std::string vecinoSalida, dummy;
                    vecinoSalida=registros.at(i).destinoIP();
                    dummy=vecinoSalida;
                    if(dummy.size()>10 && dummy.erase(10, dummy.size()) == "172.26.113")
                    {
                        int idSalida=internoDia1.add_node(vecinoSalida);
                        vecinosSalientes.push_back(idSalida);
                    }
                } else if (registros.at(i).destinoIP() == ip)
                {
                    std::string vecinoEntrada, dummy;
                    vecinoEntrada=registros.at(i).fuenteIP();
                    dummy=vecinoEntrada;
                    if(dummy.size()>10 && dummy.erase(10, dummy.size()) == "172.26.113")
                    {
                        int idEntrada=internoDia1.add_node(vecinoEntrada);
                        vecinosEntrantes.push_back(idEntrada);
                    }
                }
                i++;
            } 
        }
    }
    for(int j=0; j<vecinosEntrantes.size(); j++)
    {
        internoDia1.add_edge(vecinosEntrantes.at(j), idx.at(index));
    }
    for(int k=0; k<vecinosSalientes.size(); k++)
    {
        internoDia1.add_edge(idx.at(index), vecinosSalientes.at(k));
    }
}

#endif