#include<bits/stdc++.h>
using namespace std;

void display(vector<int> *graph, int vertex) {
    for(int i=1; i<=vertex; i++) {
        for(auto j: graph[i]) 
            cout<<i<<" --> "<<j<<endl;
        cout<<endl;
    }
}

void display_weighted(vector<pair<int, int>> *graph, int vertex) {
    for(int i=1; i<=vertex; i++) {
        for(auto p: graph[i]) 
            cout<<i<<" --> "<<p.first<<" weight = "<<p.second<<endl;
        cout<<endl;
    }
}


void undirected_graph(vector<int> *graph, int edges) {
    int vtx1, vtx2;
    for(int i=0; i<edges; i++) {
        cout<<"Enter the edge's vertex1 and vertex2 : ";
        cin>>vtx1>>vtx2;
        graph[vtx1].push_back(vtx2);
        graph[vtx2].push_back(vtx1);
    }
}


void undirected_weight_graph(vector<pair<int, int>> *graph, int edges) {
    int vtx1, vtx2, weight;
    for(int i=0; i<edges; i++) {
        cout<<"Enter the edge's vertex1, vertex2 and weight: ";
        cin>>vtx1>>vtx2>>weight;
        graph[vtx1].push_back({vtx2, weight});
        graph[vtx2].push_back({vtx1, weight});
    }
}

void directed_graph(vector<int> *graph, int edges) {
    int vtx1, vtx2;
    for(int i=0; i<edges; i++) {
        cout<<"Enter the edge's vertex1 and vertex2 : ";
        cin>>vtx1>>vtx2;
        graph[vtx1].push_back(vtx2);
    }
}

void directed_weight_graph(vector<pair<int, int>> *graph, int edges) {
    int vtx1, vtx2, weight;
    for(int i=0; i<edges; i++) {
        cout<<"Enter the edge's vertex1, vertex2 and weight: ";
        cin>>vtx1>>vtx2>>weight;
        graph[vtx1].push_back({vtx2, weight});
    }
}

int main()
{
    int vertex, edges;
    cout<<"No. of vertex = ";
    cin>>vertex;
    cout<<"No. of edges = ";
    cin>>edges;

    // Undirected Graph
    vector<int> ud_graph[vertex+1];
    undirected_graph(ud_graph, edges);
    display(ud_graph, vertex);

    // Undirected Weighted Graph
    vector<pair<int, int>> udw_graph[vertex+1];
    undirected_weight_graph(udw_graph, edges);
    display_weighted(udw_graph, edges);

    // Directed Graph
    vector<int> d_graph[vertex+1];
    directed_graph(d_graph, edges);
    display(d_graph, vertex);

    // Directed Weighted Graph
    vector<pair<int, int>> dw_graph[vertex+1];
    directed_weight_graph(dw_graph, edges);
    display_weighted(dw_graph, vertex);

    return 0;
}