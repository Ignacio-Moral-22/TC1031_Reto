#include <set>
#include <map>
#include "reto_parte_3.hpp"
#include "generar_conexiones_3.hpp"


int main(){
    std::set<std::string> hosts;
    hosts=read();
    std::map<std::string, std::string> hosts2;
    hosts2=read2();
    std::vector<class ConexionesComputadoras<std::string>> conexiones;
    conexiones = genera_conexiones();
    std::map<std::string, class ConexionesComputadoras<std::string>> diccionario;
    diccionario=diccionarios(conexiones);
    int i;
    std::cout << "Cuantas conexiones quieres ver sus IPs?" << std::endl;
    std::cin >> i;
    printUniqueIPs(diccionario, i);


}