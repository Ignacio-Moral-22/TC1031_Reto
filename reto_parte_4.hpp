#ifndef reto_parte_4_hpp
#define reto_parte_4_hpp

#include <vector>
#include <map>
#include "clase_archivo.hpp"
#include "read_csv_2.hpp"
#include "bst.hpp"

std::map<std::string, int, std::greater<>> conexionesPorDia(std::string fecha)
{
    //Gererar vector para poder hacer el mapa con los valores
    std::vector<class Registros<std::string>> registros;
    //Generar el mapa, usando greater<> para organizar de mayor a menor
    std::map<std::string, int, std::greater<>> conexionesDiarias;
    //Guardar los valores
    registros=readRecords();
    //For loop para visitar todo el vector
    for (int i=0; i<registros.size();i++){
        //Revisar si sea la fecha, y que no sea "-" el HostDestino
        if (registros.at(i).date() == fecha && registros.at(i).destinoHost() != "-"){
            //Revisar que no acabe en reto.com
            if(registros.at(i).destinoHost().erase(0, registros.at(i).destinoHost().length()-8)!="reto.com"){
                conexionesDiarias[registros.at(i).destinoHost()]++;
            }   
        }
    }

    // Funcion utilizada para probar impresiones
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

//Funcion para imprimir todos los dias y registros por dia
void diasTotales()
{
    //Generar mapa
    std::map<std::string, int> dias;
    //Generar vector con registros
    std::vector<class Registros<std::string>> registros;
    registros=readRecords();
    //Guardar fechas y registros por dia
    for(int i=0; i<registros.size(); i++)
    {
        dias[registros.at(i).date()]++;
    }

    //Loop para imprimir valores
    std::map<std::string, int>::iterator it = dias.begin();
    while (it != dias.end())
    {
        std::string ips = it->first;
        int conexiones = it->second;
        std::cout << "Fecha: " << ips << ", Conexiones: " << conexiones << std::endl;
        it++;
    }

}



//Invertir orden del mapa para usar BinarySearchTrees
std::map<int, std::string, std::greater<>> invert(std::map<std::string, int, std::greater<>> & conexionesDiarias)
{
    std::map<int, std::string, std::greater<>> mapa2;
    std::map<std::string, int> :: iterator it = conexionesDiarias.begin();
    while (it != conexionesDiarias.end())
    {
        std::string ips = it->first;
        int conexiones = it->second;
        mapa2.insert(std::make_pair(conexiones, ips));
        it++;
    }
    return mapa2;
}

//Imprimir el top n de cada fecha
void top(int n, std::string fecha)
{
    std::string str;
    int val = 0;
    //Arbol por defecto
    BinarySearchTree BST(str, val);
    //Generar mapa
    std::map<std::string, int, std::greater<>> conexionesDiarias = conexionesPorDia(fecha);
    //Invertir orden mapa
    std::map<int, std::string, std::greater<>> mapa2 = invert(conexionesDiarias);

    int i=0;
    //Guardar valores en el arbol
    std::map<int, std::string>::iterator it = mapa2.begin();
    while (it != mapa2.end())
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
    //Invertir el arbol para poder imprimir de mayor a menor
    BST.invert(BST.getRoot());
    //Imprimir inOrder, que haria de mayor a menor
    BST.inorder(BST.getRoot()); 
}

#endif // !reto_parte_4_hpp