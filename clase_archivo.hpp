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
        
        std::string date(){
            return fecha;
        };

        std::string fuenteIP(){
            return ipFuente;
        };

        std::string fuenteHost(){
            return hostNameFuente;
        };
        
        std::string destinoPuerto(){
            return puertoDestino;
        };
        
        std::string destinoHost(){
            return hostNameDestino;
        };

        std::string destinoIP(){
            return ipDestino;
        };
};


#endif