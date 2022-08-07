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
#define pp pair<int, pair<int, int>>

// with path compression
int findParent_recc(vector<int> &tree, int vtx) {
    if(vtx == tree[vtx])
        return vtx;
    return tree[vtx] = findParent_recc(tree, tree[vtx]);
}


int findParent(vector<int> &tree, int vtx) {
    if(vtx > tree.size()-1)
        return -1;

    int ind=vtx;
    while(tree[ind] != ind) 
        ind = tree[ind];

    // Update parent for next time and return its parent
    tree[vtx] = ind;
    return ind;
}

void doUnion(vector<int> &tree, vector<int> &rank, int a, int b) {
    int parentA = findParent(tree, a);
    int parentB = findParent(tree, b);

    if(parentB == parentA)
        return;

    // Perform Union
    if(rank[parentA] == rank[parentB]) {
        tree[parentB] = parentA;
        rank[parentA]++;
    }
    else if(rank[parentA] > rank[parentB]) 
        tree[parentB] = parentA;
    else
        tree[parentA] = parentB; 

}

void Kruskal(vector<pp> graph, int edge, int vertex) {

    vector<int> rank(vertex+1, 0);
    vector<int> tree(vertex+1, 0);
    vector<pair<int, int>> mst;
    int cost=0;

    for(int i=1; i<=vertex; i++) tree[i] = i;

    for(auto i: graph) {    
        int vt1 = i.second.first;
        int vt2 = i.second.second;
        if(findParent_recc(tree, vt1) != findParent_recc(tree, vt2)) {
            cost += i.first;
            mst.push_back({vt1, vt2});
            doUnion(tree, rank, vt1, vt2);
        }
    }
    
    for(auto i: mst) {
        cout<<i.first<<", "<<i.second<<endl;
    }
    cout<<"TOTAL COST = "<<cost;
    
}

bool comp1(pp a, pp b) {
    if(a.first <= b.first) 
        return true;
    return false;
}


int main()
{
    int edge=9;
    int vertex=6;
    vector<pp> graph;

    graph.push_back({2, {1, 2}});
    graph.push_back({1, {1, 4}});
    graph.push_back({5, {1, 5}});
    graph.push_back({3, {2, 3}});
    graph.push_back({3, {2, 4}});
    graph.push_back({7, {2, 6}});
    graph.push_back({5, {3, 4}});
    graph.push_back({8, {3, 6}});
    graph.push_back({9, {4, 5}});

    sort(graph.begin(), graph.end(), comp1);

    Kruskal(graph, edge, vertex);

    return 0;
}