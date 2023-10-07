/*
Find all the combination of sub set of element from the given set of 
element whoes sum is equal to given sum.

INPUT : elements=[2, 3, 4, 5], sum=7
OUTPUT:  [[2, 2, 3], [3, 4], [7]]

*/

#include<bits/stdc++.h>
using namespace std;

void display(vector<int> a) {
    cout<<"[ ";
    for(auto i: a) 
        cout<<i<<"  ";
    cout<<"]\n";
}

// Time Taken = O(2^sum  * k) k=height of tree
// Space Complexitiy = depend on no. of combinations
void comb_rep(vector<int> arr, vector<int> sub, int index, int sum, int s, vector<vector<int>> *result) {
    if(s > sum || arr[index] > sum) return;
    if(index >= arr.size()){
        if(sum == s)
            result->push_back(sub);
        return;
    }

    int temp = arr.at(index);
    sub.push_back(temp);
    s += temp;
    comb_rep(arr, sub, index, sum, s, result); 
    s-= temp;
    sub.pop_back();
    comb_rep(arr, sub, index+1, sum, s, result);
}

void comb_uniq(vector<int> arr, vector<int> sub, int index, int sum, int s, vector<vector<int>> *result) {
    if(s > sum || arr[index] > sum) return;
    if(index >= arr.size()){
        if(sum == s)
            result->push_back(sub);
        return;
    }

    int temp = arr.at(index);
    sub.push_back(temp);
    s += temp;
    comb_uniq(arr, sub, index+1, sum, s, result); 
    s-= temp;
    sub.pop_back();
    comb_uniq(arr, sub, index+1, sum, s, result);
}

void comb_uniq_nr(vector<int> arr, vector<int> sub, int index, int target, vector<vector<int>> *result) {
    if(target == 0) {
        result->push_back(sub);
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        int temp = arr.at(i);
        if(i > index && temp == arr.at(i-1)) continue;
        if(arr.at(i) > target) break;

        sub.push_back(temp);
        comb_uniq_nr(arr, sub, i+1, target-temp, result);
        sub.pop_back();
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 7};
    cout<<"Given array : ";
    display(arr);

    vector<int> sub = {};
    vector<vector<int>> result;
    int sum = 7;
    comb_rep(arr, sub, 0, sum, 0, &result);

    cout<<"Subsequence of sum "<<sum<<"  :"<<endl; 
    for(auto i: result)
        display(i);

    // Unique Combination without repeatation
    result.clear();
    set<vector<int>> res;
    vector<int> arr1 = {1, 1, 1, 2, 2};
    sum = 3;
    comb_uniq(arr1, sub, 0, sum, 0, &result);
    // Vector to set
    copy(result.begin(), result.end(), inserter(res, res.end()));
    cout<<"Unique Subsequence of sum "<<sum<<"  :"<<endl; 
    for(auto i: res)
        display(i);


    result.clear();
    vector<int> arr2 = {1, 1, 2, 2};
    sum = 3;
    comb_uniq_nr(arr2, sub, 0, sum, &result);
    cout<<"Non repeat Unique Subsequence of sum "<<sum<<"  :"<<endl; 
    for(auto i: result)
        display(i);
    return 0;
}
