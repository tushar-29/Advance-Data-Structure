/*
Kosaraju algorithm help to find all the strongly connected components (SCC) from 
the given graph.

steps 1: To sort the node according to their finishing time i.e. Topological Sorting(DFS)

step 2 : Tranpose the graph (opposit the graph's edge direction)

step 3 : Do the DFS to Tranpose graph according to finishing time of original graph
         got from Topological Sorting.
*/



#include<bits/stdc++.h>
using namespace std;

void display(vector<int> graph[], int vertex) {
    for(int i=1; i<=vertex; i++) {
        cout<<i<<" = [";
        for(auto vtx: graph[i])
            cout<<" "<<vtx;
        cout<<" ]"<<endl;
    }
}


void topologicalSort(vector<int> graph[], int visited[], int vtx, stack<int> &ans) {
    visited[vtx] = 1;
    for(auto i: graph[vtx]) {
        if(visited[i] == 0)
            topologicalSort(graph, visited, i, ans);
    }
    ans.push(vtx);
}


void getTranposeGraph(vector<int> graph[], vector<int> transGraph[], int vertex) {
    for(int i=1; i<=vertex; i++) {
        for(auto vtx: graph[i]) 
            transGraph[vtx].push_back(i);
        
    }
}


void dfs(vector<int> transGraph[], int visited[], int vtx) {
    visited[vtx] = 1;
    cout<<vtx<<", ";
    for(auto i: transGraph[vtx]) {
        if(visited[i] == 0)
            dfs(transGraph, visited, i);
    }
}


void kosaraju(vector<int> graph[], int vertex) {
    int visited[vertex+1] = {0};
    vector<int> transGraph[vertex+1];
    stack<int> ans;
    int temp=0;

    // step 1: getting topological sort arr as `ans`
    for(int i=1; i<=vertex; i++) {
        if(visited[i] == 0)
            topologicalSort(graph, visited, i, ans);
    }

    // step 2: get tranpose of the graph in `trnsGraph`
    getTranposeGraph(graph, transGraph, vertex);
    cout<<"\nTranspose Graph : \n";
    display(transGraph, vertex);


    for(int i=0; i<=vertex; i++) 
        visited[i] = 0;


    // step 3: perform dfs in transGraph where element is used from `ans` stack.
    cout<<"\nSCC are : \n";
    while(! ans.empty()) {
        temp = ans.top();
        ans.pop();
        if(visited[temp] == 0) {
            dfs(transGraph, visited, temp);
            cout<<endl;
        }
    }
}


int main()
{
    int vertex=5;
    vector<int> graph[vertex+1];

    graph[1] = {2};
    graph[2] = {3, 4};
    graph[3] = {1};
    graph[4] = {5};
    graph[5] = {};

    cout<<"Graph : \n";
    display(graph, vertex);

    kosaraju(graph, vertex);

    return 0;
}
