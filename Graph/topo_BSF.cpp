/*
BSF Topological sort use Khan's algorithm by using indegree of each vertex

Topological sort is perform in Directed A-Cyclic Graph (DAG) 

It is a linear odering of vertex such that if there is edge 
u --> v then u appear before v in that odering.

NOTE : Graph must not contain any cycle.

*/

#include<bits/stdc++.h>
using namespace std;


void get_indegree(vector<int> graph[], int indegree[], int vertex) {
    for(int j=1; j<=vertex; j++) {
        for(auto i: graph[j])
            indegree[i]++;
    }
}


void topological_sort(vector<int> graph[], int indegree[], int vertex, vector<int> &ans) {
    queue<int> q;
    int temp;

    for(int i=1; i<=vertex; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(! q.empty()) {
        temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i: graph[temp]) {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);      
        }
    }
}


void Traversal(vector<int> graph[], int vertex) {
    vector<int> ans;    
    int indegree[vertex+1]={0};
    get_indegree(graph, indegree, vertex);

    // for(int i=1; i<=vertex; i++)
    //     cout<<indegree[i]<<"  "<<i<<endl;
    // cout<<endl;

    topological_sort(graph, indegree, vertex, ans);

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