#include<bits/stdc++.h>
using namespace std;


void seq_display(int i, int n) {
    if(i > n)
        return;
    cout<<i<<endl;
    seq_display(i+1, n);
}

void opp_display(int i, int n) {
    if(i < 0)
        return;
    cout<<i<<endl;
    opp_display(i-1, n);
}

// Using Backtracking
void back_display(int i, int n) {
    if(i < 0)
        return;
    back_display(i-1, n);
    cout<<i<<endl;
}

int main()
{
    cout<<"SEQ Display : "<<endl;
    seq_display(0, 5);
    cout<<"Opposite Seq : "<<endl;
    opp_display(5, 5);
    cout<<"Opposite Seq in Backtracking: "<<endl;
    back_display(5, 5);
    return 0;
}
