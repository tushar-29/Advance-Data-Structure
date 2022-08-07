/*
Minimum Spanning Tree (MST)
The graph with `v` no. of vertex and `e` no. of edges say G(v, e) 

-->if it can be converted to G` graph with `v` no if vertex and `v-1` no of edges
that is G`(v, v-1) graph then the given graph is Spamming Tree.

-->Each vertex of the ST can reach to rest all the vertex. 

-->And the graph which give minimum weigh or distance in total that graph is said
to be MST of that graph.

NOTE : MST does not contain any cycles.

To find MST for the given graph we use two algorithms :
    i)  Prim's Algorithm (using clid and parent relations)
    ii) Kruskal's Algorithm (use of Disjoint and Union set's) 

*/

#include<bits/stdc++.h>
using namespace std;


void Prims(vector<pair<int, int>> graph[], int vertex) {
    vector<int> key(vertex, INT_MAX);
    vector<bool> mst(vertex, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> parent(vertex, -1);
    key[0] = 0;

    int i=0;
    int ind=0;
    pq.push({0, 0});

    // LOOP SHOULD GO till vertex - 1 times that is no. of edge times
   for(i=0; i<vertex; i++) {

        ind = pq.top().second;
        pq.pop();
        if(mst[ind] == false) {
            mst[ind] = true;
            for(auto j: graph[ind]) {
                if(mst[j.first] == false && j.second < key[j.first]) {
                    key[j.first] = j.second;
                    parent[j.first] = ind;
                    pq.push({j.second, j.first});
                }
            }
        }
    }

    vector<pair<int, int>> mst_graph[vertex];
    for(i=1; i<vertex; i++)
        mst_graph[parent[i]].push_back({i, key[i]});

    for(i=0; i<vertex; i++) {
        cout<<i<<" = {";
        for(auto k: mst_graph[i])
            cout<<"( "<<k.first<<", "<<k.second<<" ), ";
        cout<<"}\n";
    }
    cout<<"VALUE OF MST = "<<accumulate(key.begin(), key.end(), 0);
}


int main()
{
    int vertex=5;
    vector<pair<int, int>> graph[vertex];

    graph[0] = {{1, 2}, {3, 6}};
    graph[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    graph[2] = {{1, 3}, {4, 7}};
    graph[3] = {{0, 6}, {1, 8}};
    graph[4] = {{1, 5}, {2, 7}};

    Prims(graph, vertex);

    return 0;
}