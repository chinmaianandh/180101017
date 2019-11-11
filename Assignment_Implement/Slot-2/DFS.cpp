#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v-1].push_back(w-1);
    adj[w-1].push_back(v-1);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v+1 << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            DFSUtil(*i, visited);
    cout << v+1 << " ";
}


void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    DFSUtil(v, visited);
}



int main()
{
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Enter the vertex at which DFS starts : ";
    int x;
    cin>>x;

    g.DFS(x-1);
    cout<<endl;
    return 0;
}
