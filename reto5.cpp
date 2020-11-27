#include <iostream>
#include <vector>
#include <string>
#include "ConexionesComputadoras.hpp"
#include "generar_conexiones_3.hpp"
#include "graph.hpp"

int main()
{
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    conexiones=genera_conexiones();
    std::string ip, val;
    ip="172.26.113.";
    int idx;
    std::cout << "Escribe un numero del 1 al 150 para encontrar su IP:" << std::endl;
    std::cin >> val;
    ip.append(val);
    for(int i=0; i<conexiones.size(); i++)
    {
        if(conexiones.at(i).getIP()==ip)
        {
            Graph<std::string> grafo;
            idx=grafo.add_node(ip);
            std::vector<int> vecinosEntrantes, vecinosSalientes;
            for(int j=0; j<conexiones.at(i).getNumeroConexionesEntrantes(); j++)
            {
                std::string vecinoEntrada, dummy;
                vecinoEntrada=conexiones.at(i).getConexionesEntrantes();
                dummy=vecinoEntrada;
                if(dummy.size()>10 && dummy.erase(10, dummy.size()) == "172.26.113")
                {
                    int idEntrada=grafo.add_node(vecinoEntrada);
                    vecinosEntrantes.push_back(idEntrada);
                }
            }
            for(int k = 0; k<conexiones.at(i).getNumeroConexionesSalientes(); k++)
            {
                std::string vecinoSalida, dummy;
                vecinoSalida=conexiones.at(i).getConexionesSalientes();
                dummy=vecinoSalida;
                if(dummy.size()>10 && dummy.erase(10, dummy.size()) == "172.26.113")
                {
                    int idSalida=grafo.add_node(vecinoSalida);
                    vecinosSalientes.push_back(idSalida);
                }
            }
            for(int j=0; j<vecinosEntrantes.size(); j++)
            {
                grafo.add_edge(vecinosEntrantes.at(j), idx);
                // grafo.add_edge(idx, vecinosEntrantes.at(j));
            }
            for(int k=0; k<vecinosSalientes.size(); k++)
            {
                grafo.add_edge(idx, vecinosSalientes.at(k));
                // grafo.add_edge(vecinosSalientes.at(k), idx);
            }

            grafo.DFS(idx);
        }
    }
    return 0;
}