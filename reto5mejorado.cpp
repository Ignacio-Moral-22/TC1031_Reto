#include <iostream>
#include <vector>
#include <string>
#include "graph.hpp"
#include "read_csv_2.hpp"
#include "clase_archivo.hpp"
#include "reto_5.hpp"

int main(){
    std::vector<class Registros<std::string>> registros;
    registros = readRecords();
    std::vector<std::string> direccionesIP;
    for(int i=0; i<registros.size(); i++)
    {
        direccionesIP.push_back(registros.at(i).fuenteIP());
    }
    std::vector<int> idx;
    std::string ip, val, date;
    ip="172.26.113.";
    std::cout << "Escribe un numero del 1 al 150 para encontrar su IP:" << std::endl;
    std::cin >> val;
    ip.append(val);
    std::vector<std::string> dates;
    dates.push_back("10-8-2020");
    dates.push_back("11-8-2020");
    dates.push_back("12-8-2020");
    dates.push_back("13-8-2020");
    dates.push_back("14-8-2020");
    dates.push_back("15-8-2020");
    dates.push_back("16-8-2020");
    dates.push_back("17-8-2020");
    dates.push_back("18-8-2020");
    dates.push_back("19-8-2020");
    dates.push_back("20-8-2020");
    dates.push_back("21-8-2020");
    /*
    Graph<std::string> internoDia1;
    std::vector<int> vecinosSalientes, vecinosEntrantes;
    int i=0;
    date=registros.at(i).date();
    dates.push_back(date);
    int first = internoDia1.add_node(ip);
    idx.push_back(first);
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
            internoDia1.add_edge(vecinosEntrantes.at(j), idx.at(0));
            // grafo.add_edge(idx, vecinosEntrantes.at(j));
        }
    for(int k=0; k<vecinosSalientes.size(); k++)
        {
            internoDia1.add_edge(idx.at(0), vecinosSalientes.at(k));
            // grafo.add_edge(vecinosSalientes.at(k), idx);
        }
    */
    std::vector<class Graph<std::string>> internosPorDias;
    for(int i=0; i<dates.size(); i++)
    {
        std::vector<int> vecinosSalientes, vecinosEntrantes;
        Graph<std::string> internoPorDia;
        internoPorDia = checkGraphs(ip, idx, dates.at(i), i, vecinosEntrantes, vecinosSalientes);
        internosPorDias.push_back(internoPorDia);
        std::cout << "El dia " << dates.at(i) << " la computadora escogida tuvo estas conexiones: ";
        internosPorDias.at(i).BFS(idx.at(i));
        std::cout << std::endl;
        //Para la pregunta 2, de conexiones entrantes por dia
        if(vecinosEntrantes.size()>0)
        {
            std::cout << "\t\tEste mismo dia, se conectaron a esta computadora estas IPs: ";
            for(int j=0; j<vecinosEntrantes.size(); j++)
            {
                std::cout << internosPorDias.at(i).showValue(vecinosEntrantes.at(j)) << ", ";
            }
            std::cout << std::endl << std::endl;
        }
    }

    std::vector<class Graph<std::string>> hostsDestinosRaros;
    
    return 0;
}
