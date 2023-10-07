#include<bits/stdc++.h>
using namespace std;


int unique_path_recc(int row, int col) {
    if(row == 0 && col == 0) 
        return 1;
    
    if(row < 0 || col < 0)
        return 0;

    int sum=0;
    sum += unique_path_recc(row-1, col);
    sum += unique_path_recc(row, col-1);
    return sum;
}


int unique_path_memo(int row, int col, vector<vector<int>> &dp) {
    if(row == 0 && col ==0)
        return 1;
    if(row < 0 || col < 0)
        return 0;

    if(dp[row][col] != -1)
        return dp[row][col];
    
    int sum=0;
    sum += unique_path_memo(row-1, col, dp);
    sum += unique_path_memo(row, col-1, dp);
    
    return dp[row][col] = sum;

}


int unique_path_tabu(int row, int col) {
    vector<vector<int>> dp(row+1, vector<int> (col+1, 0));
    dp[0][0] = 1;
    for(int i=0; i<=row; i++) {
        for(int j=0; j<=col; j++) {
            if(i > 0) 
                dp[i][j] += dp[i-1][j];
            if(j > 0) 
                dp[i][j] += dp[i][j-1];
        }
    }
    return dp[row][col];
}


int unique_path_tabu2(int row, int col) {
    vector<int> prev(col+1, 0);

    for(int i=0; i<=row+1; i++) {
        vector<int> curr(col+1, 0);
        for(int j=0; j<=col; j++) {
            if(i==0 && j==0) curr[j] = 1;
            else if(j > 0) 
                curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }
    return prev[col];
}


void Main(int row, int col) {
    cout<<"Result recc = "<<unique_path_recc(row-1, col-1)<<endl;

    vector<vector<int>> dp(row, vector<int> (col, -1));
    cout<<"Result memo = "<<unique_path_memo(row-1, col-1, dp)<<endl;

    cout<<"Result tabu = "<<unique_path_tabu(row-1, col-1)<<endl;

    cout<<"Result tabu2 = "<<unique_path_tabu2(row-1, col-1)<<endl;
}


int main()
{
    int row=3;
    int col=4;

    Main(row, col);

    return 0;
}