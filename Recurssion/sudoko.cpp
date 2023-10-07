#include<bits/stdc++.h>
using namespace std;

void display(vector<string> board) {
    cout<<"+---+---+---+---+---+---+---+---+---+\n";
    for(auto i: board) {
        cout<<"| ";
        for(char j: i)
            cout<<j<<" | ";
        cout<<"\n+---+---+---+---+---+---+---+---+---+\n";
    }
    cout<<endl;
}

bool isConflit(vector<string> board, int row, int col, char k) {
    int i=0, n=board.size();

    for(i=0; i<n; i++) {
        if(board[row][i] == k || board[i][col] == k)
            return true;
        
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
            return true;
    }
    return false;
    
}

bool sudoko(vector<string> &board, int row=0) {
    static int n=board.size();

    for(int i=row; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == '.') {
                for(char k='1'; k<='9'; k++) {
                    if(!isConflit(board, i, j, k)) {
                        board[i][j] = k;
                        if(sudoko(board, i)) return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int n=9;
    vector<string> board(n);
    board[0] = "53.6789.2";
    board[1] = "672195348";
    board[2] = ".98342567";
    board[3] = "859761423";
    board[4] = "426853791";
    board[5] = "7139.4856";
    board[6] = "96.537284";
    board[7] = "287419635";
    board[8] = "345286179";

    sudoko(board);
    display(board);

    return 0;
}