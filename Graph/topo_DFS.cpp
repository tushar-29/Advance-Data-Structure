/*
Topological sort is perform in Directed A-Cyclic Graph (DAG) 

It is a linear odering of vertex such that if there is edge 
u --> v then u appear before v in that odering.

NOTE : Graph must not contain any cycle.

*/

#include<bits/stdc++.h>
using namespace std;


void topological_sort(vector<int> graph[],int visited[], int vtx, vector<int> &ans) {
    visited[vtx] = 1;
    for(auto i: graph[vtx]) {
        if(visited[i] == 0) {
            topological_sort(graph, visited, i, ans);
        }
    }
    ans.push_back(vtx);
}


void Traversal(vector<int> graph[], int vertex) {
    vector<int> ans;    
    int visited[vertex+1] = {0};

    for(int i=1; i<=vertex; i++) {
        if(visited[i] == 0)
            topological_sort(graph, visited, i, ans);
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans)
        cout<<i<<"  ";
    cout<<endl;  
}


int main()
{
    int vertex=6;
    int edge=6;
    vector<int> graph[vertex+1];

    graph[1] = {};
    graph[2] = {};
    graph[3] = {4};
    graph[4] = {2};
    graph[5] = {1, 2};
    graph[6] = {1, 3};
                
    Traversal(graph, vertex);

    return 0;
}