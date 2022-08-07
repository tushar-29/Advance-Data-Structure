#include<bits/stdc++.h>
using namespace std;

void shortest_path(vector<int> graph[], vector<int> &distance, int i_vtx) {
    queue<int> q;
    int temp=0;

    q.push(i_vtx);
    distance[i_vtx] = 0;

    while(! q.empty()) {
        temp = q.front();
        q.pop();
        for(auto i: graph[temp]) {
            if(distance[temp]+1 < distance[i]) {
                distance[i] = distance[temp]+1;
                q.push(i);
            }
        }
    }
}


void Traversal(vector<int> graph[], int vertex) {
    
    for(int i=0; i<=vertex; i++) {

        vector<int> distance(vertex+1, INT_MAX);
        shortest_path(graph, distance, i);

        for(int j=0; j<=vertex; j++)
            cout<<i<<" to "<<j<<" = "<<distance[j]<<endl;
        cout<<endl;
    }
    
}


int main()
{
    int vertex=8;
    vector<int> graph[vertex+1];

    graph[0]={1, 3};
    graph[1]={0, 2, 3};
    graph[2]={1, 6};
    graph[3]={0, 1, 4};
    graph[4]={3, 5};
    graph[5]={4, 6};
    graph[6]={2, 5, 7, 8};
    graph[7]={6, 8};
    graph[8]={6, 7};
    
    Traversal(graph, vertex);

    return 0;
}