/*
Bellman Ford Algorithm 
This algorithm is used for directed graph
To travel a graph having negative edges between the graphs


To detect negative loop of negative cycle which goes till infinity 
to detect this cycle we do : 

Relax is done for N-1 times for given vertex, and after relaxisation the
distance array is said to to minimum and cannot be futher reduce.

But if in next relaxisation text if distance array changes then, we conclude
that graph contain negative cycle loop.

*/

#include<bits/stdc++.h>
using namespace std;


void getEdges(vector<pair<int, int>> graph[], vector<pair<pair<int, int>, int>> &edgeVector, int vertex) {
    int toVtx=0, weight=0;

    for(int fromVtx=0; fromVtx<=vertex; fromVtx++) {
        for(auto p: graph[fromVtx]) {
            toVtx = p.first;
            weight = p.second;
            edgeVector.push_back({{fromVtx, toVtx}, weight});
        }
    }
}

void displayDistance(vector<int> distance, int vtx) {
    cout<<"FOR vertex : "<<vtx<<endl;
    for(int i=0; i<distance.size(); i++) {
        if(distance[i] != INT_MAX && i != vtx) 
            cout<<vtx<<" to "<<i<<" = "<<distance[i]<<endl;
    }
    cout<<endl;
}


int relax(vector<pair<pair<int, int>, int>> edgeVector, vector<int> &distance) {
    int fromVtx=0, toVtx=0, weight=0, flag=0;

    for(auto p: edgeVector) {
        fromVtx = p.first.first;
        toVtx = p.first.second;
        weight = p.second;
    
        if(distance[fromVtx] == INT_MAX) continue;

        if(distance[fromVtx] + weight < distance[toVtx]) {
            distance[toVtx] = distance[fromVtx] + weight;
            flag = 1;
        }
    }
    return flag;
}


void bellmanFord(vector<pair<pair<int, int>, int>> edgeVector, int vertex) {

    int flag=0;
    for(int i=0; i<=vertex; i++) {
        vector<int> distance(vertex+1, INT_MAX);
        distance[i] = 0;
        
        for(int j=0; j<vertex; j++) 
            flag = relax(edgeVector, distance);
        
        // cycle check
        flag = relax(edgeVector, distance);

        if(flag == 0)
            displayDistance(distance, i);
        else {
            cout<<"negative cycle present\n";
            break;
        }
    }
}


int main()
{
    // int vertex=5;
    int vertex=2;
    vector<pair<int, int>> graph[vertex+1];
    vector<pair<pair<int, int>, int>> edgeVector;
    // graph[0] = {{1, 5}};
    // graph[1] = {{2, -2}, {5, -3}};
    // graph[2] = {{4, 3}};
    // graph[3] = {{2, 6}, {4, -2}};
    // graph[4] = {};
    // graph[5] = {{3, 1}};

    graph[0] = {{1, -2}};
    graph[1] = {{2, -4}};
    graph[2] = {{0, 1}};

    getEdges(graph, edgeVector, vertex);
    bellmanFord(edgeVector, vertex);

    return 0;
}
