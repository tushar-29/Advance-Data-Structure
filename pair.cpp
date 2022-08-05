#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Pair is single layer which can be stored in contaier like
    // vector, map, array, set, etc. 
    // but not with unorder_map 

    pair<int, int>pr = {1, 2};
    cout<<pr.first<<" - "<<pr.second<<endl;

    pair<pair<int, int>, int>pr2 = {{1, 2}, 3};
    cout<<"{ "<<pr2.first.first<<" - "<<pr2.first.second<<" } "<<pr2.second<<endl;
    return 0;
    
}