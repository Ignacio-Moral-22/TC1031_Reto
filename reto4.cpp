#include <map>
#include "reto_parte_4.hpp"


int main(){
    //Genera el mapa de conexiones, utilizamos greater para organizar de mayor a menor
    std::map<std::string, int, std::greater<>> conexiones;
    //Revisar una fecha especifica
    conexiones=conexionesPorDia("10-8-2020");
    //Permite ver todos los dias, y los registros totales cada dia
    diasTotales();

    //Como son 10 dias, utilizamos 10 llamados para poder acceder a todos los dias
    top(5, "10-8-2020");
    top(5, "11-8-2020");
    top(5, "12-8-2020");
    top(5, "13-8-2020");
    top(5, "14-8-2020");
    top(5, "17-8-2020");
    top(5, "18-8-2020");
    top(5, "19-8-2020");
    top(5, "20-8-2020");
    top(5, "21-8-2020");
    return 0;
}