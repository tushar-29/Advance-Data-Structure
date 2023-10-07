#include<bits/stdc++.h>
using namespace std;


int cherry_pick_recc(vector<vector<int>> matrix, int row, int col, int r, int a, int b) {
    if(a < 0 || b > col || b < 0 || b > col)
        return -1e8;
    if(r == row) {
        if(a != b)
            return matrix[r][a] + matrix[r][b];
        return matrix[r][a];
    }

    int maxi=0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(a == b) 
                maxi = max(matrix[r][a] + cherry_pick_recc(matrix, row, col, r+1, a+i, b+j), maxi);
            else 
                maxi = max(matrix[r][a] + matrix[r][b] + cherry_pick_recc(matrix, row, col, r+1, a+i, b+j), maxi);
        }
    }
    return maxi;
}


int cherry_pick_memo(vector<vector<int>> matrix, int row, int col, int r, int a, int b, vector<vector<vector<int>>> &dp) {
    if(a < 0 || b > col || b < 0 || b > col)
        return -1e8;
    if(r == row) {
        if(a != b)
            return matrix[r][a] + matrix[r][b];
        return matrix[r][a];
    }

    if(dp[r][a][b] != -1)
        return dp[r][a][b];


    int maxi=0, value=0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(a == b) 
                value = matrix[r][a];
            else 
                value = matrix[r][a] + matrix[r][b];
            value += cherry_pick_recc(matrix, row, col, r+1, a+i, b+j);
            maxi = max(maxi, value);
        }
    }
    return dp[r][a][b] = maxi;
}


int cherry_pick_tabu1(vector<vector<int>> matrix, int row, int col) {
    vector<vector<vector<int>>> dp(row+1, vector<vector<int>>(col+1, vector<int>(col+1, 0)));

    for(int i=0; i<=col; i++) {
        for(int j=0; j<=col; j++) {
            if(i == j)
                dp[row][i][j] = matrix[row][j];
            else    
                dp[row][i][j] = matrix[row][j] + matrix[row][i];
        }
    }
    for(int i=row-1; i>=0; i--) {
        for(int a=0; a<=col; a++) {
            for(int b=0; b<=col; b++) {
                int maxi=-1e8;
                for(int j1=-1; j1<=1; j1++) {
                    for(int j2=-1; j2<=1; j2++) {
                        int value=0;
                        if(a == b) 
                            value = matrix[i][a];
                        else 
                            value = matrix[i][a] + matrix[i][b];

                        if(a+j1 >= 0 && a+j1 <= col && b+j2 >= 0 && b+j2 <= col)
                            value += dp[i+1][a+j1][b+j2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][a][b] = maxi; 
            }
        }
    }
    return dp[0][0][col];
}


int cherry_pick_tabu2(vector<vector<int>> matrix, int row, int col) {
    vector<vector<int>> dp(col+1, vector<int>(col+1, 0));

    for(int i=0; i<=col; i++) {
        for(int j=0; j<=col; j++) {
            if(i == j)
                dp[i][j] = matrix[row][j];
            else    
                dp[i][j] = matrix[row][j] + matrix[row][i];
        }
    }
    for(int i=row-1; i>=0; i--) {
        vector<vector<int>> temp(col+1, vector<int>(col+1, 0));
        for(int a=0; a<=col; a++) {
            for(int b=0; b<=col; b++) {
                int maxi=-1e8;
                for(int j1=-1; j1<=1; j1++) {
                    for(int j2=-1; j2<=1; j2++) {
                        int value=0;
                        if(a == b) 
                            value = matrix[i][a];
                        else 
                            value = matrix[i][a] + matrix[i][b];

                        if(a+j1 >= 0 && a+j1 <= col && b+j2 >= 0 && b+j2 <= col)
                            value += dp[a+j1][b+j2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                temp[a][b] = maxi; 
            }
        }
        dp = temp;
    }
    return dp[0][col];
}


void Main(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    cout<<"result recc = "<<cherry_pick_recc(matrix, row-1, col-1, 0, 0, col-1)<<endl;

    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
    cout<<"result memo = "<<cherry_pick_memo(matrix, row-1, col-1, 0, 0, col-1, dp)<<endl;
    cout<<"result tabu1 = "<<cherry_pick_tabu1(matrix, row-1, col-1)<<endl;
    cout<<"result tabu2 = "<<cherry_pick_tabu2(matrix, row-1, col-1)<<endl;
}


int main()
{
    vector<vector<int>> matrix = {
        {3, 5, 4, 2},
        {5, 2, 1, 6},
        {4, 5, 3, 3},
        {2, 4, 11, 7},
    };

    Main(matrix);

    return 0;
}
