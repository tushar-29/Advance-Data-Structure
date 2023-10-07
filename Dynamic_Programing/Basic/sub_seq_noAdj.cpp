/*
Print the maximum sum of subsequence for the array without such that the 
element picked is not adjacent to each other.

*/

#include<bits/stdc++.h>
using namespace std;


int maxSumSubSeq_recc(vector<int> arr, int ind) {
    if(ind < 0) return 0;

    int pick=0, not_pick=0;
    pick = arr[ind] + maxSumSubSeq_recc(arr, ind-2);
    not_pick = maxSumSubSeq_recc(arr, ind-1);

    return max(pick, not_pick);
}


int maxSumSubSeq_memo(vector<int> arr, int ind, int memo[]) {
    if(ind < 0) return 0;

    int pick=0, not_pick=0;
    if(memo[ind] != 0)
        return memo[ind];

    pick = arr[ind] + maxSumSubSeq_memo(arr, ind-2, memo);
    not_pick = maxSumSubSeq_memo(arr, ind-1, memo);
    
    return memo[ind] = max(pick, not_pick);
}


int maxSumSubSeq_tabu(vector<int> arr) {
    int size = arr.size();
    int dp[size] = {0};

    int pre = arr[0];
    int pre_pre = 0;
    int temp=0;
    // dp[0] = arr[0];
    
    int i=0, pick=0, not_pick=0;
    for(i=1; i<size; i++) {
        pick = arr[i];
        if(i-2 >= 0)
            // pick += dp[i-2];
            pick += pre_pre;

        not_pick = pre;

        // dp[i] = max(pick, not_pick);
        temp = max(pick, not_pick);
        pre_pre = pre;
        pre = temp;
    }

    // return dp[i-1];
    return temp;
}

void Main(vector<int> arr) {

    cout<<"maximum sum = "<<maxSumSubSeq_recc(arr, arr.size()-1)<<endl;    

    int memo[arr.size()]={0};
    cout<<"maximum sum = "<<maxSumSubSeq_memo(arr, arr.size()-1, memo)<<endl; 

    cout<<"maximum sum = "<<maxSumSubSeq_tabu(arr)<<endl;
 
}


int main()
{
    vector<int> arr = {2, 1, 4, 9};


    Main(arr);

    return 0;
}