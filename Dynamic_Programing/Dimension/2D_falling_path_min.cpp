/*

Here We need to find Minimum or Maximum sum of path whoes starting point is 
variable and ending point is also variable.

starting point is 1st row and ending point is last row.
*/

#include<bits/stdc++.h>
using namespace std;


int falling_path_min_recc(vector<vector<int>> maze, int row, int col) {
    if(row < 0 || col < 0 || col >= maze[row].size())
        return INT_MAX;
    if(row == 0)
        return maze[row][col];

    int upUp=INT_MAX, upLeft=INT_MAX, upRight=INT_MAX;
    int temp = falling_path_min_recc(maze, row-1, col);
    if(temp != INT_MAX)
        upUp = maze[row][col] + temp;
    
    temp = falling_path_min_recc(maze, row-1, col-1);
    if(temp != INT_MAX)
        upLeft = maze[row][col] + temp;
    
    temp = falling_path_min_recc(maze, row-1, col+1);
    if(temp != INT_MAX)
        upRight = maze[row][col] + temp; 

    return min(min(upUp, upLeft), upRight);
}


int falling_path_min_memo(vector<vector<int>> maze, int row, int col,
    vector<vector<int>> &dp) {
    if(row < 0 || col < 0 || col >= maze[row].size())
        return INT_MAX;
    if(row == 0)
        return maze[row][col];

    if(dp[row][col] != -1)
        return dp[row][col];

    int upUp=INT_MAX, upLeft=INT_MAX, upRight=INT_MAX;
    int temp = falling_path_min_recc(maze, row-1, col);
    if(temp != INT_MAX)
        upUp = maze[row][col] + temp;
    
    temp = falling_path_min_recc(maze, row-1, col-1);
    if(temp != INT_MAX)
        upLeft = maze[row][col] + temp;
    
    temp = falling_path_min_recc(maze, row-1, col+1);
    if(temp != INT_MAX)
        upRight = maze[row][col] + temp; 

    return dp[row][col] = min(min(upUp, upLeft), upRight);
}


int falling_path_min_tabu1(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<vector<int>> dp(row, vector<int> (col, 0));
    dp[0] = maze[0];

    int downD=0, downL=0, downR=0;
    for(int i=1; i<row; i++) {
        for(int j=0; j<col; j++) {
            downD=INT_MAX, downL=INT_MAX, downR=INT_MAX;
            downD = maze[i][j] + dp[i-1][j];
            if(j > 0)
                downL = maze[i][j] + dp[i-1][j-1];
            if(j < col-1)
                downR = maze[i][j] + dp[i-1][j+1];
            dp[i][j] = min(min(downD, downL), downR);
        }
    }
    return *min_element(dp[row-1].begin(), dp[row-1].end());
}


int falling_path_min_tabu2(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    vector<int> prev = maze[0];

    int downD=0, downL=0, downR=0;
    for(int i=1; i<row; i++) {
        vector<int> curr(col, 0);
        for(int j=0; j<col; j++) {
            downD=INT_MAX, downL=INT_MAX, downR=INT_MAX;
            downD = maze[i][j] + prev[j];
            if(j > 0)
                downL = maze[i][j] + prev[j-1];
            if(j < col-1)
                downR = maze[i][j] + prev[j+1];
            curr[j] = min(min(downD, downL), downR);
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}


void Main(vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();

    int small=INT_MAX, temp=0;
    for(int i=0; i<col; i++) {
        temp = falling_path_min_recc(maze, row-1, i);
        if(small > temp)
            small = temp;
    }
    cout<<"Result recc = "<<small<<endl;

    small = INT_MAX;
    vector<vector<int>> dp(row, vector<int>(col, -1));
    for(int i=0; i<col; i++) {
        temp = falling_path_min_memo(maze, row-1, i, dp);
        if(small > temp)
            small = temp;
    }
    cout<<"Result Memo = "<<small<<endl;
    cout<<"Result Tabu1 = "<<falling_path_min_tabu1(maze)<<endl;
    cout<<"Result Tabu2 = "<<falling_path_min_tabu2(maze)<<endl;
}  


int main()
{
    vector<vector<int>> maze = {
        {1, 2, 10, 4},
        {3, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    Main(maze);

    return 0;
}