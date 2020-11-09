#include <set>
#include <map>
#include "reto_parte_3.hpp"
#include "generar_conexiones_3.hpp"
/*
Ignacio Joaquin Moral
Parte 3 del Reto
Finalizado: 08/11/2020
            DD/MM/YYYY
*/


int main(){
    //Generar el Set
    std::set<std::string> hosts;
    //Guardar el valor en el set
    hosts=read();
    //Generar vector para guardar tanto ips como hostnames
    std::vector<class Registros<std::string>> hosts2;
    //Guardar valores
    hosts2=read2();
    //Crear mapa con anomalias
    std::map<std::string, std::string> ipAnomalos;
    //Guardar ips y nombres
    ipAnomalos=getIPAnomalo(hosts, hosts2, "c8dzweh1e382v74a2pn5.xxx", "v7lgvx4laf7ba9xmzhnh.com");
    //Generar vector de objetos ConexionesComputadoras
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    //Guardar conexiones
    conexiones = genera_conexiones();
    //Generar mapa de ips y conexiones
    std::map<std::string, class ConexionesComputadoras<std::string>> diccionario;
    //Guardar valores
    diccionario=diccionarios(conexiones);
    //Poder escribir los valores que quieras
    int i;
    std::cout << "Cuantas conexiones quieres ver sus IPs?" << std::endl;
    std::cin >> i;
    //Loop con strings para buscar conexiones salientes y ver si se conecta con ips anomalos
    printUniqueIPs(diccionario, i, ipAnomalos, "c8dzweh1e382v74a2pn5.xxx", "v7lgvx4laf7ba9xmzhnh.com");
    return 0;
}