#ifndef reto_parte_4_hpp
#define reto_parte_4_hpp

#include <vector>
#include <map>
#include "clase_archivo.hpp"
#include "read_csv_2.hpp"
#include "bst.hpp"

std::map<std::string, int, std::greater<>> conexionesPorDia(std::string fecha)
{
    std::vector<class Registros<std::string>> registros;
    std::map<std::string, int, std::greater<>> conexionesDiarias;
    registros=readRecords();
    for (int i=0; i<registros.size();i++){
        if (registros.at(i).date() == fecha && registros.at(i).destinoHost() != "-"){
            if(registros.at(i).destinoHost().erase(0, registros.at(i).destinoHost().length()-8)!="reto.com"){
                conexionesDiarias[registros.at(i).destinoHost()]++;
            }   
        }
    }

    // std::map<std::string, int>::iterator it = conexionesDiarias.begin();
    // while (it != conexionesDiarias.end())
    // {
    //     std::string ips = it->first;
    //     int conexiones = it->second;
    //     std::cout << "Host Name Destino: " << ips << ", Conexiones: " << conexiones << std::endl;
    //     it++;
    // }

    return conexionesDiarias;
}

void diasTotales()
{
    std::map<std::string, int> dias;
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    for(int i=0; i<registros.size(); i++)
    {
        dias[registros.at(i).date()]++;
    }

    std::map<std::string, int>::iterator it = dias.begin();
    while (it != dias.end())
    {
        std::string ips = it->first;
        int conexiones = it->second;
        std::cout << "Fecha: " << ips << ", Conexiones: " << conexiones << std::endl;
        it++;
    }

}

// void top(int n, std::string fecha)
// {
//     std::map<std::string, int> conexiones;
//     conexiones=conexionesPorDia(fecha);
//     BinarySearchTree<int> BST;
//     std::map<std::string, int>::iterator it = conexiones.begin();
//     while (it != conexiones.end())
//     {
//         std::string ips = it->first;
//         int conexion = it->second;
//         BST.insert_node(conexion);
//         it++;
//     }
//     BST.print_preorder();
//     BST.inverse(BST.root);
//     BST.print_preorder();

// }


std::map<int, std::string, std::greater<>> invert(std::map<std::string, int, std::greater<>> & mymap)
{
    std::map<int, std::string, std::greater<>> multiMap;

    std::map<std::string, int> :: iterator it = mymap.begin();
    while (it != mymap.end())
    {
        std::string ips = it->first;
        int conexiones = it->second;
        multiMap.insert(std::make_pair(conexiones, ips));
        it++;
    }
    return multiMap;
}

void top(int n, std::string fecha)
{
    std::string str;
    int val = 0;
    BinarySearchTree BST(str, val);
    std::map<std::string, int, std::greater<>>dict = conexionesPorDia(fecha);
    std::map<int, std::string, std::greater<>> newmap = invert(dict);

    int i=0;
    std::map<int, std::string>::iterator it = newmap.begin();
    while (it != newmap.end())
    {
        int conexiones = it->first;
        std::string ips = it->second;
        if(i<n)
        {
            BST.insert(BST.getRoot(), ips, conexiones);
            i++;
        }
        it++;
    }

    std::cout << std::endl;
    BST.invert(BST.getRoot());
    BST.inorder(BST.getRoot()); 
}

#endif // !reto_parte_4_hpp