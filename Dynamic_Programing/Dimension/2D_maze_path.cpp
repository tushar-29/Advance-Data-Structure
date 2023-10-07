#include<bits/stdc++.h>
using namespace std;


int maze_path_recc(vector<vector<int>> maze, int row, int col) {
    if(row == 0 && col == 0)
        return 1;
    
    if(row < 0 || col < 0 || maze[row][col] == -1)
        return 0;
    
    int sum=0;
    sum += maze_path_recc(maze, row-1, col);
    sum += maze_path_recc(maze, row, col-1);
    return sum;
}


int maze_path_memo(vector<vector<int>> maze, int row, int col, vector<vector<int>> &dp) {
    if(row == 0 && col == 0)
        return 1;

    if(row < 0 || col < 0 || maze[row][col] == -1)
        return 0;
    
    if(dp[row][col] != -1)
        return dp[row][col];

    int sum=0;
    sum += maze_path_memo(maze, row-1, col, dp);
    sum += maze_path_memo(maze, row, col-1, dp);

    return dp[row][col] = sum;
}


int maze_path_tabu1(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(maze[i][j] == -1)
                dp[i][j] = 0;
            else {
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[row-1][col-1];
}


int maze_path_tabu2(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<int> dp(col, 0);
    for(int i=0; i<row; i++) {
        vector<int> temp(col, 0);
        for(int j=0; j<col; j++) {
            if(i >= 0 && j >= 0 &&  maze[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
            if(i == 0  && j == 0) {
                temp[j] = 1;
                continue;
            }
            temp[j] = 0;
            if(i > 0) temp[j] += dp[j];
            if(j > 0) temp[j] += temp[j-1];
        }
        dp = temp;
    }
    return dp[col-1];
}


void Main(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    cout<<"Result Recc = "<<maze_path_recc(maze, row-1, col-1)<<endl;
    
    vector<vector<int>> dp(row, vector<int>(col, -1));
    cout<<"Result Memo = "<<maze_path_memo(maze, row-1, col-1, dp)<<endl;

    cout<<"Result Tabu1 = "<<maze_path_tabu1(maze)<<endl;
    cout<<"Result Tabu2 = "<<maze_path_tabu2(maze)<<endl;
}


int main()
{
    vector<vector<int>> maze = {
        {0, 0, -1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };

    Main(maze);

    return 0;
}