#include<bits/stdc++.h>
using namespace std;


void display(vector<int> distance, int src) {
    for(int i=0; i<distance.size(); i++) {
        if(!(distance[i] == INT_MAX || distance[i] == 0))
            cout<<src<<" to "<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;
}


void shortest_path(vector<pair<int, int>> graph[], vector<int> &distance, int i_vtx) {
    queue<int> q;
    int temp=0;

    q.push(i_vtx);
    distance[i_vtx] = 0;

    while(! q.empty()) {
        temp = q.front();
        q.pop();
        for(auto i: graph[temp]) {
            int vt = i.first;
            int weight = i.second;
            if((distance[temp] + weight) < distance[vt]) {
                distance[vt] = distance[temp] + weight;
                q.push(vt);
            }
        }
    }
}


void Traversal(vector<pair<int, int>> graph[], int vertex) {
    
    for(int i=0; i<=vertex; i++) {
        vector<int> distance(vertex+1, INT_MAX);
        shortest_path(graph, distance, i);
        display(distance, i);
    }
    
}

void topological_sort(vector<pair<int, int>> graph[],int visited[], int vtx, stack<int> &ans) {
    visited[vtx] = 1;
    for(auto i: graph[vtx]) {
        if(visited[i.first] == 0) {
            topological_sort(graph, visited, i.first, ans);
        }
    }
    ans.push(vtx);
}


void Traversal2(vector<pair<int, int>> graph[], int vertex) {
    stack<int> ans;    
    int visited[vertex+1] = {0};
    vector<int> distance(vertex+1, INT_MAX);

    for(int i=0; i<=vertex; i++) {
        if(visited[i] == 0)
            topological_sort(graph, visited, i, ans);
    }

    int temp=0;
    while(! ans.empty()) {
        temp = ans.top();
        ans.pop();
        vector<int> distance(vertex+1, INT_MAX);
        shortest_path(graph, distance, temp);
        display(distance, temp);
    }
}

int main()
{
    int vertex=5;
    vector<pair<int, int>> graph[vertex+1];

    graph[0]={{1, 2}, {4, 1}};
    graph[1]={{2, 3}};
    graph[2]={{3, 6}};
    graph[3]= {};
    graph[4]={{2, 2}, {5, 4}};
    graph[5]={{3, 1}};
    
    Traversal(graph, vertex);

    cout<<"\nMETHOD 2 : \n";
    Traversal2(graph, vertex);

    return 0;
}