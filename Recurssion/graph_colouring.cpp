#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int> graph[], int visited[], int color, int vtx) {
    int set_color[color+1]={0};
    int color_no = 0;
    for(int i: graph[vtx]) {
        if(visited[i] != 0) 
            set_color[visited[i]] = 1;
    }
    for(int i=1; i<=color; i++) {
        if(set_color[i] == 0)
            return i;
    }
    return color_no;
}


bool graphColoring(vector<int> graph[], int visited[], int color, int vtx=0) {
    int color_no = isPossible(graph, visited, color, vtx);

    if(color_no != 0) {
        visited[vtx] = color_no;
        for(int i: graph[vtx]) {
            if(visited[i] == 0)
                if(graphColoring(graph, visited, color, i)) return true;
        }
        return true;
    }
    else return false;
}


void countGraphColor(vector<int> graph[], int vertex, int color) {
    int visited[vertex+1]={0};

    for(int i=0; i<=vertex; i++) {
        if(visited[i] == 0)
            if(! graphColoring(graph, visited, color, i)) {
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

    graph[0] = {1, 2, 3};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1};
    graph[3] = {0, 1};

    int color=3;
    countGraphColor(graph, vertex, color);

    return 0;
}