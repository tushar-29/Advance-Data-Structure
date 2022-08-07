#include<bits/stdc++.h>
using namespace std;
 
void BSF(vector<int> graph[], int vtx, int visited[]) {
    queue<int> q;
    int temp=0;

    q.push(vtx);

    while(! q.empty()) {
        temp = q.front();
        q.pop();

        for(auto i: graph[temp]) {
            if(visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

void Traversal(vector<int> graph[], int vertex) {
    int visited[vertex + 1] = {0}, i=0;

    for(i=1; i<=vertex; i++) 
        BSF(graph, i, visited);
}



int main()
{
    int vertex=8;
    vector<int> graph[vertex+1];

    graph[1] = {};
    graph[2] = {};
    graph[3] = {};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};
    graph[7] = {};
    graph[8] = {};


    return 0;
}