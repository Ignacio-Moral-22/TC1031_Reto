#ifndef clase_archivo_hpp
#define clase_archivo_hpp
#include <string>
#include <iostream>

template<class T>
class Registros{
    private:
        T fecha, hora, ipFuente, puertoFuente, hostNameFuente, ipDestino, puertoDestino, hostNameDestino;
    public:
        Registros(){};
        Registros(T f, T h, T ipf, T pf, T hnf, T ipd, T pd, T hnd){
            fecha = f;
            hora = h;
            ipFuente = ipf;
            puertoFuente = pf;
            hostNameFuente = hnf;
            ipDestino = ipd;
            puertoDestino = pd;
            hostNameDestino = hnd;
        };
        ~Registros(){};

        void print(){
            //std::cout << "Fecha: " << fecha << ", Hora: " << hora << ", IP Fuente: " << ipFuente << "\n";
            std::cout << "Host Name Fuente: " << hostNameFuente << std::endl;
        };
        
        std::string date(){
            return fecha;
        };

        std::string fuenteHost(){
            return hostNameFuente;
        };
        /*
        std::string hora(){
            return hora;
        };
        */
};


#endif