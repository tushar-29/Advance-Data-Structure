#include<bits/stdc++.h>
using namespace std;

template <typename T>
void display(T a) {
    cout<<"[ ";
    for(auto i: a) 
        cout<<i<<" ";
    cout<<"]\n";
}

bool comp1(int a, int b) {
    return a >= b ? true : false;
}

set<int> all_combination_sum(vector<int> arr, int index, int sum) {
    static set<int> sum_arr;
    if(index >= arr.size()) {
        sum_arr.insert(sum);
        return sum_arr;
    }
    
    sum_arr = all_combination_sum(arr, index+1, sum);
    sum += arr.at(index);
    sum_arr = all_combination_sum(arr, index+1, sum);
    return sum_arr;
}

set<vector<int>> all_combination(vector<int> arr, int index, vector<int> sub) {
    static set<vector<int>> comb_arr;
    if(index >= arr.size()) {
        comb_arr.insert(sub);
        return comb_arr;
    }

    for(int i=index; i<arr.size(); i++) {
        int temp = arr.at(i);
        if(i > index && temp == arr.at(i-1)) continue;

        comb_arr = all_combination(arr, i+1, sub);
        sub.push_back(temp);
        comb_arr = all_combination(arr, i+1, sub); 
        sub.pop_back();
    }
    return comb_arr;
}

int main()
{
    vector<int> arr = {3, 1, 2};
    display<vector<int>>(arr);

    set<int> result = all_combination_sum(arr, 0, 0);
    cout<<"Result array : "<<endl;
    display<set<int>>(result);

    cout<<"\n-------------\n\nAll non repeation Combination : \n";
    vector<int> arr1 = {1, 2, 2};
    vector<int> sub;
    display<vector<int>>(arr1);

    set<vector<int>> result1 = all_combination(arr1, 0, sub);
    cout<<"Result array : "<<endl;
    for(auto i: result1)
        display<vector<int>>(i);
    return 0;
}