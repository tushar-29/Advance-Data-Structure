#include<bits/stdc++.h>
using namespace std;


int sum_path_recc(vector<vector<int>> maze, int row, int col) {
    if(row < 0 || col < 0)
        return 0;
    if(row == 0 && col == 0)
        return maze[row][col];
    
    int up=INT_MAX, right=INT_MAX;
    if(row > 0)
        up = sum_path_recc(maze, row-1, col) + maze[row][col];
    if(col > 0)
        right = sum_path_recc(maze, row, col-1) + maze[row][col];
    return min(up, right);
}


int sum_path_memo(vector<vector<int>> maze, int row, int col, vector<vector<int>> &dp) {
    if(row < 0 || col < 0)
        return 0;
    
    if(row == 0 && col == 0)
        return maze[row][col];

    if(dp[row][col] != -1)
        return dp[row][col];

    int up=INT_MAX, right=INT_MAX;
    if(row > 0)
        up = sum_path_memo(maze, row-1, col, dp) + maze[row][col];
    if(col > 0)
        right = sum_path_memo(maze, row, col-1, dp) + maze[row][col];
    
    return dp[row][col] = min(up, right);
}


int sum_path_tabu1(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(i == 0 && j == 0) {
               dp[i][j] = maze[i][j];
               continue;
            }

            int up=INT_MAX, right=INT_MAX;
            if(i > 0)
                up = dp[i-1][j] + maze[i][j];
            if(j > 0)
                right = dp[i][j-1] + maze[i][j];
            dp[i][j] = min(up, right);
        }
    }
    return dp[row-1][col-1];
}


int sum_path_tabu2(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<int> prev(col, 0);

    for(int i=0; i<row; i++) {
        vector<int> curr(col, 0);
        for(int j=0; j<col; j++) {
            if(i == 0 && j == 0) {
                curr[j] = maze[i][j];
                continue;
            }

            int up=INT_MAX, right=INT_MAX;
            if(i > 0)
                up = prev[j] + maze[i][j];
            if(j > 0)
                right = curr[j-1] + maze[i][j];
            
            curr[j] = min(up, right);
        }
        prev = curr;
    }
    return prev[col-1];
}


void Main(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    cout<<"Sum recc = "<<sum_path_recc(maze, row-1, col-1)<<endl;

    vector<vector<int>> dp(row, vector<int>(col, -1));
    cout<<"Sum memo = "<<sum_path_memo(maze, row-1, col-1, dp)<<endl;

    cout<<"Sum tabu1 = "<<sum_path_tabu1(maze)<<endl;

    cout<<"Sum tabu2 = "<<sum_path_tabu2(maze)<<endl;
}


int main()
{
    vector<vector<int>> maze = {
        {5, 9, 4, 1},
        {4, 3, 2, 7},
        {1, 3, 6, 4},
    };

    Main(maze);

    return 0;
}