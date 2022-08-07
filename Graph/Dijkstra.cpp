#include<bits/stdc++.h>
using namespace std;


void display(vector<int> distance, int vtx) {
    for(int i=1; i<distance.size(); i++) {
        if(!(distance[i] == INT_MAX || distance[i] == 0))
            cout<<vtx<<" to "<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;
}


void dijkstra(vector<pair<int, int>> graph[], vector<int> &distance, int vtx) {
    // minimum priority queue(distance, vertex)
    priority_queue<pair<int, int>> pq;
    int temp=0, weight=0;

    pq.push({0, vtx});
    distance[vtx] = 0;

    while(! pq.empty()) {
        temp = pq.top().second;
        weight = pq.top().first;
        pq.pop();

        for(auto i: graph[temp]) {
            if(weight + i.second < distance[i.first]) {
                distance[i.first] = i.second + weight;
                pq.push({distance[i.first], i.first});
            }
        }
    }
}


void Traversal(vector<pair<int, int>> graph[], int vertex) {
    for(int i=1; i<=vertex; i++) {
        vector<int> distance(vertex+1, INT_MAX);
        dijkstra(graph, distance, i);
        display(distance, i);   
    }
}


int main()
{
    int vertex=5;
    vector<pair<int, int>> graph[vertex+1];

    graph[1] = {{2, 2}, {4, 1}};
    graph[2] = {{1, 2}, {3, 4}, {5, 5}};
    graph[3] = {{2, 4}, {4, 3}, {5, 1}};
    graph[4] = {{1, 1}, {3, 3}};
    graph[5] = {{2, 5}, {3, 1}};

    Traversal(graph, vertex);

    return 0;
}