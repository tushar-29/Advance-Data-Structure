/*
A graph can have different connnected and non-connected components belong to same graph
so, we need to find all the dfs for each vertex for non-connected graph

But if graph has one singal conmponent the single dfs will is enough for traversal.
*/

#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int> *graph, int vtx, int *visited) {
    stack<int> s;
    int temp;

    visited[vtx] = 1;
    s.push(vtx);

    while(! s.empty()) {
        temp = s.top();
        s.pop();
        cout<<temp<<", ";
        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
}


void DFS_recc(vector<int> *graph, int vtx, int *visited) {
    visited[vtx] = 1;
    cout<<vtx<<", ";
    for(auto i: graph[vtx]) {
        if(visited[i] == 0) {
            DFS_recc(graph, i, visited);
        }
    }
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0};
    for(int i=1; i<=vertex; i++) {
        if(!visited[i])
            DFS_recc(graph, i, visited);
    }
}

int main()
{
    int vertex=7; 
    int edges=6;
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {1, 4, 7};
    graph[3] = {5};
    graph[4] = {2, 6};
    graph[5] = {3};
    graph[6] = {4, 7};
    graph[7] = {2, 6};

    // graph[1] = {2, 3};
    // graph[2] = {1, 4};
    // graph[3] = {1, 5, 6};
    // graph[4] = {2};
    // graph[5] = {3, 7};
    // graph[6] = {3};
    // graph[7] = {5};

    Traversal(graph, vertex);
    

    return 0;
}
// Time Complexicity = O(no_of_vertex + adjescent_vertex_traveling_time) = O(N+E)
// Space Compexicity = O(adjescent_matix + queue_size + visited_size) = O((N+E)+(N)+(N))
