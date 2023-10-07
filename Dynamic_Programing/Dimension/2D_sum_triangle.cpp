#include<bits/stdc++.h>
using namespace std;


int sum_path_tri_recc1(vector<vector<int>> maze, int row, int col) {
    if(row == 0 && col == 0)
        return maze[row][col];
    
    if(row < 0 || col < 0 || row < col)
        return INT_MAX;
    
    int upup=0, upleft=0, upright=0;

    upup = sum_path_tri_recc1(maze, row-1, col);
    if(upup != INT_MAX)
        upup += maze[row][col]; 

    upleft = sum_path_tri_recc1(maze, row-1, col-1);
    if(upleft != INT_MAX)
        upleft += maze[row][col];

    upright = sum_path_tri_recc1(maze, row-1, col+1);
    if(upright != INT_MAX)
        upright += maze[row][col];


    return min(min(upup, upleft), upright);
}


int sum_path_tri_recc2(vector<vector<int>> maze, int siz, int row, int col) {
    if(row == siz-1 && row >= col)
        return maze[row][col];

    if(row >= siz || col >= siz || row < col || col < 0)
        return INT_MAX;


    int downdown=0, downleft=0, downright=0;
     
    downdown = sum_path_tri_recc2(maze, siz, row+1, col);
    if(downdown != INT_MAX)
        downdown += maze[row][col]; 

    downleft = sum_path_tri_recc2(maze, siz, row+1, col-1);
    if(downleft != INT_MAX)
        downleft += maze[row][col];

    downright = sum_path_tri_recc2(maze, siz, row+1, col+1);
    if(downright != INT_MAX)
        downright += maze[row][col];

    return min(min(downdown, downleft), downright);
} 


int sum_path_tri_memo(vector<vector<int>> maze, int siz, int row, int col,
    vector<vector<int>> &dp) {
    if(row == siz-1 && row >= col)
        return maze[row][col];

    if(row >= siz || col >= siz || row < col || col < 0)
        return INT_MAX;

    if(dp[row][col] != -1)
        return dp[row][col];

    int downdown=0, downleft=0, downright=0;
     
    downdown = sum_path_tri_memo(maze, siz, row+1, col, dp);
    if(downdown != INT_MAX)
        downdown += maze[row][col]; 

    downleft = sum_path_tri_memo(maze, siz, row+1, col-1, dp);
    if(downleft != INT_MAX)
        downleft += maze[row][col];

    downright = sum_path_tri_memo(maze, siz, row+1, col+1, dp);
    if(downright != INT_MAX)
        downright += maze[row][col];

    return dp[row][col] = min(min(downdown, downleft), downright);
} 


int sum_path_tri_tabu1(vector<vector<int>> maze) {
    int row = maze.size();

    vector<vector<int>> dp(row);
    int j=0, i=0;
    for(i=0; i<row; i++) {
        for(j=0; j<maze[i].size(); j++) 
            dp[i].push_back(0);
    }
    for(i=0; i<maze[row-1].size(); i++)
        dp[row-1][i] = maze[row-1][i];

    
    for(i=row-2; i>=0; i--) {
        for(j=i; j>=0; j--) {
            int upup=0, upleft=0, upright=0;
            upup = maze[i][j] + dp[i+1][j];
            upleft = maze[i][j] + dp[i+1][j-1];
            upright = maze[i][j] + dp[i+1][j+1];
            dp[i][j] = min(min(upup, upright), upleft);
        }
    }
    return dp[0][0];
}

int sum_path_tri_tabu2(vector<vector<int>> maze) {
    int row = maze.size();

    vector<int> dp(maze[row-1].size(), 0);
    int j=0, i=0;

    for(i=0; i<maze[row-1].size(); i++)
        dp[i] = maze[row-1][i];


    for(i=row-2; i>=0; i--) {
        vector<int> curr(maze[i].size(), 0);
        for(j=i; j>=0; j--) {
            int upup=0, upleft=0, upright=0;
            upup = maze[i][j] + dp[j];
            upleft = maze[i][j] + dp[j-1];
            upright = maze[i][j] + dp[j+1];
            curr[j] = min(min(upup, upright), upleft);
        }
        dp = curr;
    }
    return dp[0];
}


void Main(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[row-1].size();

    int small=INT_MAX;
    for(int i=0; i<col; i++) {
        int ans = sum_path_tri_recc1(maze, row-1, i);
        if(small > ans)
            small = ans;
    }
    cout<<"Sum Recc1 = "<<small<<endl;

    cout<<"Sum recc2 = "<<sum_path_tri_recc2(maze, row, 0, 0)<<endl;

    vector<vector<int>> dp(row);
    for(int i=0; i<row; i++) {
        for(int j=0; j<maze[i].size(); j++) 
            dp[i].push_back(-1);
    }
    cout<<"Sum memo = "<<sum_path_tri_memo(maze, row, 0, 0, dp)<<endl;

    cout<<"Sum tabu1 = "<<sum_path_tri_tabu1(maze)<<endl;

    cout<<"Sum tabu2 = "<<sum_path_tri_tabu2(maze)<<endl;
}


int main()
{
    vector<vector<int>> maze = {
        {1},
        {2, 1},
        {11, 6, 1},
        {8, 9, 6, 1},
        {2, 5, 0, 4, 3},
    };

    Main(maze);

    return 0;
}