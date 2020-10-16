#pragma once
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
        ConexionesComputadoras(){};
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

        void printIP(){
            std::cout << ip << std::endl;
        }

};