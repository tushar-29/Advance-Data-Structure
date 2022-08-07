#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<int> *graph, int vtx, int *visited) {
    queue<pair<int, int>> q;
    int temp, parent;

    visited[vtx] = 1;
    q.push({vtx, -1});

    while(! q.empty()) {
        temp = q.front().first;
        parent = q.front().second;
        q.pop();
        // cout<<temp<<", ";
        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                q.push({i, temp});
                visited[i] = 1;
            }
            else if(parent != i)
                return true;
        }
    }
    return false;
}


void Traversal(vector<int> *graph, int vertex) {
    int visited[vertex+1] = {0};
    for(int i=1; i<=vertex; i++) {
        if(!visited[i]) {
            if(isCycle(graph, i, visited)) {
                cout<<"Graph has a cycle"<<endl;
                return;
            }
        }
    }
    cout<<"Graph does not have a cycle"<<endl;
}


int main()
{
    int vertex=11; 
    int edges=10;
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {1, 4};
    graph[3] = {5};
    graph[4] = {2};
    graph[5] = {3, 6, 10};
    graph[6] = {5, 7};
    graph[7] = {6, 8};
    graph[8] = {7, 9, 11};
    graph[9] = {8, 10};
    graph[10] = {5, 9};
    graph[11] = {8};

    Traversal(graph, vertex);

    return 0;
}