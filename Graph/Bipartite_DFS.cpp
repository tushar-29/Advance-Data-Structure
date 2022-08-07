/*
Check weather weather given graph is bipartite or not : 
Graph which can be colored exartly by two colors such that no two adjuscent vertex have
same color is called bipartite graph

Here, 
if graph has a cycle then,
    if cycle length is even then it can be bipartite
    if cycle length is odd then it can not be biparite
*/

#include<bits/stdc++.h>
using namespace std;


bool isBipartite(vector<int> *graph, int vtx, int *visited) {
    stack<int> s;
    int temp;

    visited[vtx] = 1;
    s.push(vtx);

    while(! s.empty()) {
        temp = s.top();
        s.pop();
        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                s.push(i);
                visited[i] = visited[temp] * -1;
            }
            else if(visited[i] == visited[temp])
                return false;
        }
    }
    return true;
}


bool isBipartite_recc(vector<int> *graph, int vtx, int *visited, int color=1) {
    visited[vtx] = color;
    for(auto i: graph[vtx]) {
        if(visited[i] == 0) 
            return isBipartite_recc(graph, i, visited, color * -1);
        else if(visited[i] == color)
            return false;
    }
    return true;
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0};
    for(int i=1; i<=vertex; i++) {
        if(!visited[i]) {
            if(! isBipartite(graph, i, visited)){
                cout<<"not bipartite graph\n";
                return;
            }
        }
    }
    cout<<"Bipartitie graph\n";
}

int main()
{
    int vertex=8; 
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {1, 3, 6};
    graph[3] = {2, 4};
    graph[4] = {3, 5};
    graph[5] = {4, 6, 7};
    graph[6] = {2, 5};
    graph[7] = {5, 8};
    graph[8] = {7};

    Traversal(graph, vertex);
    

    return 0;
}