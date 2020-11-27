#include <iostream>
#include <vector>
#include <string>
#include "graph.hpp"
#include "read_csv_2.hpp"
#include "clase_archivo.hpp"
#include "reto_5.hpp"
/*
Ignacio Joaquin Moral
A01028470
*/
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
    
    //Esta funcion genera el vector de grafos de conexiones internas
    std::vector<class Graph<std::string>> internosPorDias;
    for(int i=0; i<dates.size(); i++)
    {
        std::vector<int> vecinosSalientes, vecinosEntrantes;
        Graph<std::string> internoPorDia;
        internoPorDia = checkGraphs(ip, idx, dates.at(i), i, vecinosEntrantes, vecinosSalientes);
        internosPorDias.push_back(internoPorDia);
        std::cout << "El dia " << dates.at(i) << " la computadora escogida tuvo estas conexiones: ";
        internosPorDias.at(i).BFS(idx.at(i));
        // Para la pregunta 2, de conexiones entrantes por dia
        if(vecinosEntrantes.size()>0)
        {
            std::cout  << "\t\tLas conexiones entrantes a esta ip en este dia fueron " << vecinosEntrantes.size() << std::endl;
        }
    }
    std::cout << std::endl;
    
    //Esta parte de la funcion permite buscar cuantas conexiones al IP anomalo se hicieron.
    std::string ipAnomalo = "c8dzweh1e382v74a2pn5.xxx";
    std::vector<class Graph<std::string>> hostsDestinos;
    for(int i=0; i<dates.size(); i++)
    {
        std::vector<int> vecinosEntrantes;
        Graph<std::string> hostsDestinoAnomalos;
        hostsDestinoAnomalos = checkGraphsHosts(ipAnomalo, idx, dates.at(i), i, vecinosEntrantes);
        hostsDestinos.push_back(hostsDestinoAnomalos);
        if(vecinosEntrantes.size()>0)
        {
            std::cout << "El dia " << dates.at(i) << " se conectaron " << vecinosEntrantes.size() << " computadoras al ip Anomalo." << std::endl;
        }
    }
    std::cout << std::endl;

    //Esta parte de la funcion permite buscar el IP mas transcurrido
    std::string ipTranscurrido = "freemailserver.com";
    std::vector<class Graph<std::string>> hostsDestinosTranscurridos;
    for(int i=0; i<dates.size(); i++)
    {
        std::vector<int> vecinosEntrantes;
        Graph<std::string> hostsDestinoTranscurrido;
        hostsDestinoTranscurrido = checkGraphsHosts(ipTranscurrido, idx, dates.at(i), i, vecinosEntrantes);
        hostsDestinosTranscurridos.push_back(hostsDestinoTranscurrido);
        if(vecinosEntrantes.size()>0)
        {
            std::cout << "El dia " << dates.at(i) << " se conectaron " << vecinosEntrantes.size() << " computadoras al ip Transcurrido." << std::endl;
        }
    }    
    return 0;
}
