#ifndef ConexionesComputadoras_hpp
#define ConexionesComputadoras_hpp
#include <stack>
#include <queue>
#include <iostream>

template<typename T>
class ConexionesComputadoras{
    private:
        T ip;
        T nombre;
        std::stack<T> conexionesEntrandes;
        std::queue<T> conexionesSalientes;
    
    public:
        //Constructor por defecto
        ConexionesComputadoras(){};
        //Destructor por defecto
        ~ConexionesComputadoras(){};

        void setIP(T ip_){
            ip=ip_;
        }

        void setNombre(T nombre_){
            nombre=nombre_;
        }

        void setConexionesEntrantes(std::stack<T> conexionesEntrantes_){
            conexionesEntrandes=conexionesEntrantes_;
        }

        void setConexionesSalientes(std::queue<T> conexionesSalientes_){
            conexionesSalientes=conexionesSalientes_;
        }

        std::string getIP(){
            return ip;
        }
        
        std::string getNombre(){
            return nombre;
        }

        std::string getConexionesEntrantes(){
           std::string retornar = conexionesEntrandes.top();
           conexionesEntrandes.pop();
           return retornar;
        }

        std::string getConexionesSalientes(){
            std::string retornar = conexionesSalientes.back();
            conexionesSalientes.pop();
            return retornar;
        }

        int getNumeroConexionesEntrantes(){
            return conexionesEntrandes.size();
        }

        int getNumeroConexionesSalientes(){
            return conexionesSalientes.size();
        }
};

#endif