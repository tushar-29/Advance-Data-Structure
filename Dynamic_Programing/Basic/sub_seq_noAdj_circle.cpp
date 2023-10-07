/*
Question: To find the maximum value subsequence form the circular array such 
that no two adjcent element is taken. 
NOTE : first and last element in the array is adjcent.

*/

#include<bits/stdc++.h>
using namespace std;


int subSeqAdjCircle_recc(vector<int> arr, int ind) {
    if(ind < 0) return 0;

    int pick=0, not_pick=0;
    pick = arr[ind] + subSeqAdjCircle_recc(arr, ind - 2);
    not_pick = subSeqAdjCircle_recc(arr, ind-1);

    return max(pick, not_pick);
}


void Main(vector<int> arr, int size) {

    vector<int> temp1, temp2;
    for(int i=0; i<size; i++) {
        if(i != 0) temp1.push_back(arr[i]);
        if(i != size-1) temp2.push_back(arr[i]);
    }
    int ans = max(subSeqAdjCircle_recc(temp1, size-1), subSeqAdjCircle_recc(temp2, size-1));

    cout<<"Ans = "<<ans<<endl;

}


int main()
{
    vector<int> arr = {4, 3, 2, 5, 7, 1, 6};

    Main(arr, arr.size());

    return 0;
}