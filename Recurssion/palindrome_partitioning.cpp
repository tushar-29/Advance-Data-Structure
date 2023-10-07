#include<bits/stdc++.h>
using namespace std;

void display(vector<string> ans) {
    cout<<"{";
    for(string i: ans) {
            cout<<i<<", ";
        }
    cout<<"}"<<endl;
}


string isPallondrome(string st, int startInd, int endInd) {

    while(startInd <= endInd) {
        if(st[startInd++] != st[endInd--]) 
            return string("");
    }
    
    return st.substr(startInd, endInd-startInd+1);
}


void partition(string st, int size, int startInd, vector<string> &ans) {
    if(startInd == size) {
        display(ans);
        return;
    }

    for(int i=startInd; i<size; i++) {
        string subStr = isPallondrome(st, startInd, i);
        if(subStr.length() != 0) {
            ans.push_back(subStr);
            partition(st, size, i+1, ans);
            ans.pop_back();
        }
    }
}


int main()
{
    string st = "aabb";
    vector<string> ans;

    partition(st, st.size(), 0, ans);
    
    

    return 0;
}