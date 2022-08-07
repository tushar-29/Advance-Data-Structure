#include<bits/stdc++.h>
using namespace std;


void find_point(vector<int> *graph, int vtx, int oldvtx, int visited[], int lowTime[], int insertTime[]) {
    static int insertT=1;

    visited[vtx] = 1;
    insertTime[vtx] = insertT;
    lowTime[vtx] = insertT++;  
    int child=0;

    for(auto i: graph[vtx]) {
        if(i == oldvtx) continue;

        if(visited[i] == 0) {
            find_point(graph, i, vtx, visited, lowTime, insertTime);

            if(lowTime[i] < lowTime[vtx])
                lowTime[vtx] = lowTime[i]; 

            //  -1 parent since starting node will not be de-tach from its img back part
            //  so to avid that we use oldvtx != -1 for 1st eleemnt of graph.
            if(lowTime[i] >= insertTime[vtx] && oldvtx != -1)
                cout<<"Point = "<<vtx<<endl;

            child++;
        }
        else {
            if(insertTime[i] < lowTime[vtx])
                lowTime[vtx] = insertTime[i];
        }
    }

    if(oldvtx == -1 && child > 1)
        cout<<"Point = "<<vtx<<endl;
}


void Articulation_Point(vector<int> graph[], int vertex) {
    int lowTime[vertex+1]={0}, insertTime[vertex+1]={0}, visited[vertex+1]={0};
    
    find_point(graph, 1, -1, visited, lowTime, insertTime);

    
}


int main()
{
    int vertex=12;
    vector<int> graph[vertex+1];
    graph[1] = {2, 4};
    graph[2] = {1, 3};
    graph[3] = {2, 4};
    graph[4] = {1, 3, 5};
    graph[5] = {4, 6};
    graph[6] = {5, 7, 9};
    graph[7] = {6, 8};
    graph[8] = {7, 9, 10};
    graph[9] = {6, 8};
    graph[10] = {8, 11, 12};
    graph[11] = {10, 12};
    graph[12] = {10, 11};

    Articulation_Point(graph, vertex);

    return 0;

    return 0;
}