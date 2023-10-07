#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


bool isConflit(vector<string> &board, int n, int row, int col) {
    for(int c=0; c<col; c++) {  //IM step just check before column
        for(int r=0; r<n; r++) {
            if(board[r][c] == 'Q') {
                if(r == row) return true;           // check for row
                if(c+r == row+col) return true;     // digonal 1 check
                if(r-c == row-col) return true;     // digonal 2 check
            }
        }
    }
    return false;
}

void solve(vector<string> &board, int n, int col, vector<vector<string>> &ans) {

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++) {
        if(!isConflit(board, n, row, col)) {
            board[row][col] = 'Q';
            solve(board, n, col+1, ans);
            board[row][col] = '.';
        }
    }
}

void solve_2(vector<string> &board, int n, int col, int *leftRow, 
int  *lowerD, int *upperD, vector<vector<string>> &ans) {

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++) {
        if(leftRow[row] == 0 && lowerD[row+col] == 0 && upperD[(n-1)-(col-row)] == 0) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperD[(n-1)-(col-row)] = 1;
            lowerD[row+col] = 1;

            solve(board, n, col+1, ans);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperD[(n-1)-(col-row)] = 0;
            lowerD[row+col] = 0;
        }
    }
}

vector<vector<string>> n_queen(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++) 
        board[i] = s;

    solve(board, n, 0, ans);
    return ans;

}

vector<vector<string>> n_queen_2(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++) 
        board[i] = s;

    int leftRow[n]={0}, lowerD[n+n-2]={0}, upperD[n+n-2]={0};
    solve_2(board, n, 0, leftRow, lowerD, upperD, ans);
    return ans;

}


int main()
{
    cout<<"METHOD - 1 : "<<endl;
    auto start = high_resolution_clock::now();
    vector<vector<string>> ans = n_queen(8);
    auto stop = high_resolution_clock::now();

    for(auto i: ans) {
        for(auto j: i) 
            cout<<j<<endl;
        cout<<endl; 
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\nTime taken by function: "<<duration.count()<<" microseconds"<<endl;

    // ------------------------------------------------------------------

    cout<<"\n\nMETHOD - 2 : "<<endl;
    start = high_resolution_clock::now();
    vector<vector<string>> ans_2 = n_queen_2(8);
    stop = high_resolution_clock::now();

    for(auto i: ans_2) {
        for(auto j: i) 
            cout<<j<<endl;
        cout<<endl; 
    }

    duration = duration_cast<microseconds>(stop - start);
    cout<<"\nTime taken by function: "<<duration.count()<<" microseconds"<<endl;
    return 0;
}