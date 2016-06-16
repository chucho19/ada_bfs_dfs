
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Grafos
{
    int V;
    list<int> *adj;
public:
    Grafos(int V);
    void anadirArista(int v, int w);
    void BFS(int s);
};

Grafos::Grafos(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Grafos::anadirArista(int v, int w){
    adj[v].push_back(w);
}

void Grafos::BFS(int s){
    bool *visitados = new bool[V];
    list<int> cola;
    for(int i = 0; i < V; i++)
        visitados[i] = false;
    
    visitados[s] = true;
    cola.push_back(s);
    list<int>::iterator i;
    
    while(!cola.empty()){
        s = cola.front();
        cout << s << " ";
        cola.pop_front();
        
        for(i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visitados[*i]){
                visitados[*i] = true;
                cola.push_back(*i);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    Grafos grafot(6);
    grafot.anadirArista(0, 1);  grafot.anadirArista(0, 2);
    grafot.anadirArista(1, 2);  grafot.anadirArista(2, 0);
    grafot.anadirArista(2, 3);  grafot.anadirArista(4, 3);
    grafot.anadirArista(3, 3);  grafot.anadirArista(1, 4);
    grafot.anadirArista(0, 3);  grafot.anadirArista(3, 5);
    grafot.BFS(2);
    cout<<endl;
    
    return 0;
}