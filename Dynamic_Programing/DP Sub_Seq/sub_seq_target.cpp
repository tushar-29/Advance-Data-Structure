#include<bits/stdc++.h>
using namespace std;


int subSeq_recc(vector<int> arr, int target, int ind) {
    if(target == 0)
        return true;
    if(ind == 0)
        return (arr[0] == target);

    bool not_taken = subSeq_recc(arr, target, ind-1);
    bool taken = false;
    if(target >= arr[ind])
        taken=subSeq_recc(arr, target-arr[ind], ind-1);

    return (not_taken || taken);
}

int subSeq_memo(vector<int> arr, int target, int ind, vector<vector<int>> &dp) {
    if(target == 0)
        return true;
    if(ind == 0)
        return (arr[0] == target);

    if(dp[ind][target] != -1)
        return dp[ind][target];

    bool not_taken = subSeq_memo(arr, target, ind-1, dp);
    bool taken = false;
    if(target >= arr[ind])
        taken=subSeq_memo(arr, target-arr[ind], ind-1, dp);

    return dp[ind][target] = (not_taken || taken);
}


int subSeq_tabu1(vector<int> arr, int target) {
    int siz = arr.size();
    
    vector<vector<int>> dp(siz, vector<int>(target+1, 0));

    for(int i=0; i<siz; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int i=1; i<siz; i++) {
         for(int t=1; t<=target; t++) {
             bool not_taken = dp[i-1][t];
            bool taken = false;
            if(t >= arr[i])
                taken=dp[i-1][t-arr[i]];
            dp[i][t] = (not_taken || taken);
         }
    }
    return dp[siz-1][target];
}


int subSeq_tabu2(vector<int> arr, int target) {
    int siz = arr.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    dp[arr[0]] = 1;

    for(int i=1; i<siz; i++) {
        vector<int> temp(target+1, 0);
        temp[0] = 1;
         for(int t=1; t<=target; t++) {
             bool not_taken = dp[t];
            bool taken = false;
            if(t >= arr[i])
                taken=dp[t-arr[i]];
            temp[t] = (not_taken || taken);
        }
        dp = temp;
    }

    return dp[target];
}


void Main(vector<int> arr, int target) {

    cout<<"Result Recc = "<<subSeq_recc(arr, target, arr.size()-1)<<endl;

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
    cout<<"Result Memo = "<<subSeq_memo(arr, target, arr.size()-1, dp)<<endl;
    cout<<"Result Tabu1 = "<<subSeq_tabu1(arr, target)<<endl;
    cout<<"Result Tabu2 = "<<subSeq_tabu2(arr, target)<<endl;
}


int main()
{
    vector<int> arr={1, 2, 3, 4, 5, 6, 7};
    int target=11;


    Main(arr, target);

    return 0;
}