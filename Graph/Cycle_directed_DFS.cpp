#include<bits/stdc++.h>
using namespace std;


bool isCycle(vector<int> graph[], int vtx, int visited[]) {
    stack<pair<int, int>> s;
    int temp=0, parent=0;

    s.push({vtx, -1});

    while(! s.empty()) {
        temp = s.top().first;
        parent = s.top().second;
        s.pop();

        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                visited[i] = 1;
                s.push({i, temp});
            }
            else if(i != parent)
                return true;
        }
    }
    return false;
}


bool isCycle_recc(vector<int> graph[], int vtx, int visited[], int d_visited[]) {
    visited[vtx] = 1;
    d_visited[vtx] = 1;

    for(auto i: graph[vtx]) {
        if(visited[i] == 0) {
            if(isCycle_recc(graph, i, visited, d_visited)) return true;
        }
        else if(d_visited[i] == 1) {
            return true;
        }
    }
    d_visited[vtx] = 0;
    return false;
}


void Traversal(vector<int> graph[], int vertex) {
    int visited[vertex + 1] = {0}, i=0;

    for(i=1; i<=vertex; i++) {
        if(visited[i] == 0) {
            int d_visited[vertex+1]={0};
            if(isCycle_recc(graph, i, visited, d_visited)) {
                cout<<"Cycle present\n";
                return;
            }
        }
    }
    cout<<"No cycle present\n";
}


int main()
{
    int vertex=9;
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {3};
    graph[3] = {4, 6};
    graph[4] = {5};
    graph[5] = {};
    graph[6] = {5};
    graph[7] = {2, 8};
    graph[8] = {9};
    graph[9] = {7};

    Traversal(graph, vertex);

    return 0;
}
