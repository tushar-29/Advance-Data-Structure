#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


template <typename T>
void display(T a) {
    cout<<"[ ";
    for(auto i: a) 
        cout<<i<<" ";
    cout<<"]\n";
}

vector<vector<int>> permutation(vector<int> arr, vector<int> sub, int *include) {
    static vector<vector<int>> res_arr;
    static int n = arr.size();

    if(sub.size() == n ) {
        res_arr.push_back(sub);
        return res_arr;
    }

    for(int j=0; j<n; j++) {
        if(include[j] == 0) {
            include[j] = 1;
            sub.push_back(arr.at(j));
            res_arr = permutation(arr, sub, include);
            include[j] = 0;
            sub.pop_back();
        }
    }
    return res_arr;
}

vector<vector<int>> permutation_1(vector<int> arr, int index) {
    static vector<vector<int>> result;

    if(index == arr.size()) {
        result.push_back(arr);
        return result;
    }

    for(int i=index; i<arr.size(); i++) {
        swap(arr.at(index), arr.at(i));
        permutation_1(arr, index+1);
        swap(arr.at(index), arr.at(i));
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> sub;
    int include[arr.size()] = {0};

    auto start = high_resolution_clock::now();
    vector<vector<int>> result = permutation(arr, sub, include);
    auto stop = high_resolution_clock::now();
    

    for(auto i: result)
        display<vector<int>>(i);

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\nTime taken by function: "<<duration.count()<<" microseconds"<<endl;

    // ------------------------------------------------------------------------------

    cout<<"METHOD 2"<<endl<<endl;

    vector<int> arr_1 = {1, 2, 3};

    start = high_resolution_clock::now();
    vector<vector<int>> result_1 = permutation_1(arr_1, 0);
    stop = high_resolution_clock::now();
    
    cout<<"RESULT : \n";
    for(auto i: result_1)
        display<vector<int>>(i);

    duration = duration_cast<microseconds>(stop - start);
    cout<<"\nTime taken by function: "<<duration.count()<<" microseconds"<<endl;

    return 0;
} 