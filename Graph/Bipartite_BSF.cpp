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
    queue<int> q;
    int temp;

    visited[vtx] = 1;
    q.push(vtx);

    while(! q.empty()) {
        temp = q.front();
        q.pop();

        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                q.push(i);
                visited[i] = visited[temp] * -1;
            }
            else if(visited[temp] == visited[i])
                return false;
        }
    }
    return true;
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0}, i;

    // For 1 component
    // isBipartite(graph, i, visited);

    // For 2 or more components
    for(i=1; i<=vertex; i++) {
        if(!visited[i]) {
            if(!isBipartite(graph, i, visited)) {
                cout<<"Not a bipartite graph\n";
                return;
            }
        }
    }
    cout<<"Graph is bipartitie"<<endl;
}


int main()
{
    int vertex=8; 

    vector<int> graph[vertex+1];

    // graph[1] = {2};
    // graph[2] = {1, 3, 8};
    // graph[3] = {2, 4};
    // graph[4] = {3, 5};
    // graph[5] = {4, 6, 8};
    // graph[6] = {5, 7};
    // graph[7] = {6};
    // graph[8] = {2, 5};

    graph[1] = {2};
    graph[2] = {1, 3, 7};
    graph[3] = {2, 4};
    graph[4] = {3, 5};
    graph[5] = {4, 6, 8};
    graph[6] = {5, 7};
    graph[7] = {2 ,6};
    graph[8] = {5};

    Traversal(graph, vertex);
    

    return 0;
}