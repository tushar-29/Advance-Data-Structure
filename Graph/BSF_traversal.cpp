/*
A graph can have different connnected and non-connected components belong to same graph
so, we need to find all the bsf for each vertex for non-connected graph

But if graph has one singal conmponent the single bsf will is enough for traversal.
*/

#include<bits/stdc++.h>
using namespace std;


void BSF(vector<int> *graph, int vtx, int *visited) {
    queue<int> q;
    int temp;

    visited[vtx] = 1;
    q.push(vtx);

    while(! q.empty()) {
        temp = q.front();
        q.pop();
        cout<<temp<<", ";
        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0};
    for(int i=1; i<=vertex; i++) {
        if(!visited[i])
            BSF(graph, i, visited);
    }
}

int main()
{
    int vertex=7; 
    int edges=6;
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {1, 3, 7};
    graph[3] = {2, 5};
    graph[4] = {6};
    graph[5] = {3, 7};
    graph[6] = {4};
    graph[7] = {2, 5};

    Traversal(graph, vertex);
    

    return 0;
}
// Time Complexicity = O(no_of_vertex + adjescent_vertex_traveling_time) = O(N+E)
// Space Compexicity = O(adjescent_matix + queue_size + visited_size) = O((N+E)+(N)+(N))
