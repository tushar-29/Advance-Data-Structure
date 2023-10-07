#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<vector<int>> graph, int row, int col) {
    if(row < 0 || col < 0 || row >= graph.size() || col >= graph.size() || graph[row][col] != 1)
        return false;
    return true;
}


void travel(vector<vector<int>> graph, int size,
    vector<vector<int>> visited, int row, int col, string &ans) {
    
    if(row == size-1 && col == size-1) {
        cout<<ans<<endl;
        return;
    }
    
    if(visited[row][col] == 0) {
        visited[row][col] = 1;

        // check down
        if(isPossible(graph, row+1, col)) {
            ans.push_back('D');
            travel(graph, size, visited, row+1, col, ans);
            ans.pop_back();
        }

        // check left
        if(isPossible(graph, row, col-1)) {
            ans.push_back('L');
            travel(graph, size, visited, row, col-1, ans);
            ans.pop_back();
        }

        // check right
        if(isPossible(graph, row, col+1)) {
            ans.push_back('R');
            travel(graph, size, visited, row, col+1, ans);
            ans.pop_back();
        }
        
        // check up
        if(isPossible(graph, row-1, col)) {
            ans.push_back('U');
            travel(graph, size, visited, row-1, col, ans);
            ans.pop_back();
        }
    }
}


void rateMaze(vector<vector<int>> graph, int size) {
    vector<vector<int>> visited(size, vector<int>(size, 0));
    string ans;
    travel(graph, size, visited, 0, 0, ans);
}


int main()
{
    int size=4;
    vector<vector<int>> graph = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };

    rateMaze(graph, size);

    return 0;
}
