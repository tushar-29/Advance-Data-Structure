#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> graph[], int visited[], int col, int vtx) {
    for(int i: graph[vtx]) {
        if(visited[i] == col) return false;
    }
    
    return true;
}


bool graphColoring(vector<int> graph[], int visited[], int color, int vertex, int vtx=0) {
    if(vtx == vertex+1) return true;

    for(int i=1; i<=color; i++) {
        if(isPossible(graph, visited, i, vtx)) {
            visited[vtx] = i;
            if(graphColoring(graph, visited, color, vertex, vtx+1)) return true;
            visited[vtx] = 0;
        }
    }
    return false;
}


void countGraphColor(vector<int> graph[], int vertex, int color) {
    int visited[vertex+1]={0};

    for(int i=0; i<=vertex; i++) {
        if(visited[i] == 0)
            if(! graphColoring(graph, visited, color, vertex, i)) {
                cout<<"Cannot be color graph by "<<color<<" colors\n";
                return;
            }
    }
    
    for(int i=0; i<=vertex; i++) {
        cout<<"vertex "<<i<<" colored with color = "<<visited[i]<<endl;
    }
}


int main()
{
    int vertex=3;
    vector<int> graph[vertex+1];

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 3};
    graph[3] = {1, 2};

    int color=2;
    countGraphColor(graph, vertex, color);

    return 0;
}