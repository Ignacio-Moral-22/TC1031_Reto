#include <map>
#include "reto_parte_4.hpp"


int main(){
    std::map<std::string, int> conexiones;
    // conexiones=conexionesPorDia("10-8-2020");
    diasTotales();
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