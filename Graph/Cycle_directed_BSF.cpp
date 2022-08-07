/*
BSF Topological sort use Khan's algorithm by using indegree of each vertex

But to find cycle we reverse the logic that if we are unable to generate 
Topological sort then the graph cotain cycle

Topological sort is perform in Directed A-Cyclic Graph (DAG) 

It is a linear odering of vertex such that if there is edge 
u --> v then u appear before v in that odering.


*/

#include<bits/stdc++.h>
using namespace std;


void get_indegree(vector<int> graph[], int indegree[], int vertex) {
    for(int j=1; j<=vertex; j++) {
        for(auto i: graph[j])
            indegree[i]++;
    }
}

bool isCyclic(vector<int> graph[], int indegree[], int vertex, vector<int> &ans) {
    queue<int> q;
    int temp, counter=0;

    for(int i=1; i<=vertex; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(! q.empty()) {
        temp = q.front();
        q.pop();
        counter++;
        ans.push_back(temp);
        for(auto i: graph[temp]) {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);      
        }
    }
    if(counter == vertex) return false;
    return true;
}


void Traversal(vector<int> graph[], int vertex) {
    vector<int> ans;    
    int indegree[vertex+1]={0};
    get_indegree(graph, indegree, vertex);

    // for(int i=1; i<=vertex; i++)
    //     cout<<indegree[i]<<"  "<<i<<endl;
    // cout<<endl;

    if(isCyclic(graph, indegree, vertex, ans)) {
        cout<<"Graph contain cycle\n";
        return;
    }
    for(auto i: ans)
        cout<<i<<"  ";
    cout<<endl;  
}


int main()
{
    // int vertex=6;
    int vertex=4;
    int edge=6;
    vector<int> graph[vertex+1];

    // graph[1] = {};
    // graph[2] = {};
    // graph[3] = {4};
    // graph[4] = {2};
    // graph[5] = {1, 2};
    // graph[6] = {1, 3};

    graph[1] = {2};
    graph[2] = {3};
    graph[3] = {4};
    graph[4] = {2};
                
    Traversal(graph, vertex);


    return 0;
}