#include<bits/stdc++.h>
using namespace std;


bool isCycle(vector<int> *graph, int vtx, int *visited) {
    stack<pair<int, int>> s;
    int temp, parent;

    visited[vtx] = 1;
    s.push({vtx, -1});

    while(! s.empty()) {
        temp = s.top().first;
        parent = s.top().second;
        s.pop();
        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                s.push({i, temp});
                visited[i] = 1;
            }
            else if(parent != i)
                return true;
        }
    }
    return false;
}


bool isCycle_recc(vector<int> *graph, int vtx,  int *visited, int parent=-1) {
    visited[vtx] = 1;
    for(auto i: graph[vtx]) {
        if(visited[i] == 0) {
            return isCycle_recc(graph, i, visited, vtx);
        }
        else if(parent != i)
            return true;
    }
    return false;
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0};
    for(int i=1; i<=vertex; i++) {
        if(!visited[i]) {
            if(isCycle_recc(graph, i, visited)) {
                cout<<"Graph has cycle"<<endl;
                return;
            }
        }
    }
    cout<<"Graph has no cycle"<<endl;
}

int main()
{
    int vertex=8; 
    int edges=7;
    vector<int> graph[vertex+1];

    graph[1] = {3};
    graph[2] = {5};
    graph[3] = {1, 4};
    graph[4] = {3};
    graph[5] = {2, 6, 8};
    graph[6] = {5, 7};
    graph[7] = {6, 8};
    graph[8] = {5, 7};


    Traversal(graph, vertex);
    

    return 0;
}
// Time Complexicity = O(no_of_vertex + adjescent_vertex_traveling_time) = O(N+E)
// Space Compexicity = O(adjescent_matix + queue_size + visited_size) = O((N+E)+(N)+(N))
