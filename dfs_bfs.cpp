
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class grafo{
    int V;
    list<int> *adj;
    void DFS_visita(int v, bool visitado[]);
public:
    grafo(int V);
    void agregar_edge(int v, int w);
    void BFS(int s);
    void DFS(int v);
};

grafo::grafo(int V){
    this->V = V;
    adj = new list<int>[V];
}

void grafo::agregar_edge(int v, int w){
    adj[v].push_back(w);
}



void grafo::BFS(int s){
    bool *visitados = new bool[V];
    for(int i = 0; i < V; i++)
        visitados[i] = false;
    list<int> queue;
    visitados[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); i++){
            if(!visitados[*i]){
                visitados[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void grafo::DFS_visita(int v, bool visitados[]){
    visitados[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visitados[*i])
            DFS_visita(*i, visitados);
}

void grafo::DFS(int v){
    bool *visitados = new bool[V];
    for (int i = 0; i < V; i++)
        visitados[i] = false;
    DFS_visita(v, visitados);
}

int main(int argc, const char * argv[]) {
    grafo comodin(9);
    comodin.agregar_edge(0, 1); comodin.agregar_edge(0, 3);
    comodin.agregar_edge(3, 1); comodin.agregar_edge(1, 4);
    comodin.agregar_edge(4, 3); comodin.agregar_edge(2, 4);
    comodin.agregar_edge(2, 5); comodin.agregar_edge(5, 5);
    cout<<"DFS: "<<endl;
    comodin.DFS(2);
    cout<<endl;
    return 0;
}