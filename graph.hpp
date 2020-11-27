#pragma once
#include <vector>
#include <stack>
#include <queue>

using namespace std;
template<typename T>
class Nodo
{
    private:
        T value;
        std::vector<int> adjacents;
    
    public:
        ~Nodo() {};
        Nodo() {};
        Nodo(T _val) {value = _val;};

        T get_val() {return value;};
        void set_val(T _val) {value = _val;};

        std::vector<int> get_adj() {return adjacents;};
        void add_to_adj(int idx) {adjacents.push_back(idx);};
};

template <class T>
class Graph
{
private:
    std::vector<Nodo<T>> nodos;
    bool is_directed;

public:
    ~Graph() {};
    Graph() {is_directed=true;};

    int add_node(T val)
    {
        for(size_t idx = 0; idx<nodos.size(); idx++)
        {
            if(nodos.at(idx).get_val() == val)
            {
                return idx;
            }
        }
        Nodo<T> node(val);
        nodos.push_back(node);
        return nodos.size()-1;
    };

    void add_edge(int src, int dst)
    {
        nodos[src].add_to_adj(dst);
        if (!is_directed)
            nodos[dst].add_to_adj(src);
    };

    void BFS(int start_vertex)
    {
        std::vector<int> visited(nodos.size(), 0);
        std::queue<int> neighbors;
        visited.at(start_vertex)=1;
        std::cout << nodos.at(start_vertex).get_val() << " ";
        std::vector<int> adjacents;
        adjacents=nodos.at(start_vertex).get_adj();
        for(int i=0; i<adjacents.size();i++)
        {
            neighbors.push(adjacents.at(i));
        }
        while(!neighbors.empty())
        {
            int temp = neighbors.front();
            if(visited.at(temp)==0)
            {
                visited.at(temp)=1;
                std::cout << nodos.at(temp).get_val() << " ";
                std::vector<int> adjacents;
                adjacents=nodos.at(temp).get_adj();
                for(int i=0; i<adjacents.size();i++)
                {
                    neighbors.push(adjacents.at(i));
                }
            }
            neighbors.pop();
        }

        std::cout << std::endl;
    }

    void DFS(int start_vertex)
    {
        std::vector<int> visited(nodos.size(), 0);
        std::stack<int> neighbors;
        visited.at(start_vertex)=1;
        std::cout << nodos.at(start_vertex).get_val() << " ";
        std::vector<int> adjacents;
        adjacents=nodos.at(start_vertex).get_adj();
        for(int i=0; i<adjacents.size();i++)
        {
            neighbors.push(adjacents.at(i));
        }
        while(!neighbors.empty())
        {
            int temp = neighbors.top();
            neighbors.pop();
            if(visited.at(temp)==0)
            {
                visited.at(temp)=1;
                std::cout << nodos.at(temp).get_val() << " ";
                std::vector<int> adjacents;
                adjacents=nodos.at(temp).get_adj();
                for(int i=0; i<adjacents.size();i++)
                {
                    neighbors.push(adjacents.at(i));
                }
            }
            
        }

        std::cout << std::endl;
    }

};
