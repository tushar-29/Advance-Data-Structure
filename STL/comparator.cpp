#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr){
    for(auto i : arr)
        cout<<i<<", ";
    cout<<endl;
}

bool comp1(int a, int b) {
    return a >= b ?  true :  false;
}

bool comp2(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first)
        return true;
    else if(a.first == b.first){
        if(a.second > b.second){
            return true;
        }
        return false;
    }
    return false;
}

int main()
{
    vector<int> arr = {8, 3, 2, 7, 5, 1, 9, 4};
    // asending sorting
    sort(arr.begin(), arr.end());
    display(arr);

    vector<int> arr1 = {8, 3, 2, 7, 5, 1, 9, 4};
    // descending sorting
    sort(arr1.begin(), arr1.end(), comp1);
    display(arr1);

    vector<pair<int, int>> arr2 = {{5, 6}, {2, 7}, {4, 2}, {1, 2}, {5, 1}, {2, 6}};
    // descending sorting
    sort(arr2.begin(), arr2.end(), comp2);
    
    for(auto i : arr2){
            cout<<"("<<i.first<<", "<<i.second<<"), ";
    }
    cout<<endl;



    return 0;
}