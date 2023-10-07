#include<bits/stdc++.h>
using namespace std;

void display(vector<int> a) {
    cout<<"( ";
    for(auto i: a)
        cout<<i<<" ";
    cout<<")"<<endl;
}

// Time Complexity = O(n*2^n)
// Space Complexity is stack size = height of tree = O(n)
// Get all sub_sequences
void sub_sequence(vector<int> arr, vector<int> seq, int ind) {
    if (ind == arr.size()) {
        display(seq);
        return;
    }
    sub_sequence(arr, seq, ind+1);
    seq.push_back(arr.at(ind));
    sub_sequence(arr, seq, ind+1);
    seq.pop_back(); // optional
}

// Get all subsequence whoes sum is equal to given sum
void sum_sequence(vector<int> arr, vector<int> seq, int ind, int sum) {
    if(ind == arr.size()) {
        if(sum == 3)
            display(seq);
        return;
    }
    if(sum > 3) return;

    sum_sequence(arr, seq, ind+1, sum);
    seq.push_back(arr.at(ind));
    sum += arr.at(ind);
    sum_sequence(arr, seq, ind+1, sum);

    sum -= arr.at(ind);
    seq.pop_back(); 
}

// Print just one subsequence then : 
bool any_one_subsequence(vector<int> arr, vector<int> seq, int ind, int sum) {
    if(ind == arr.size()) {
        if(sum == 3) {
            display(seq);
            return true;
        }
        return false;
    }
    if(sum > 3) return false;

    seq.push_back(arr.at(ind));
    sum += arr.at(ind);

    if (any_one_subsequence(arr, seq, ind+1, sum)) return true;

    sum -= arr.at(ind);
    seq.pop_back();
    return any_one_subsequence(arr, seq, ind+1, sum);
}

// // Print no of subsequence whoes sum : 
// int get_count(vector<int> arr, vector<int> seq, int ind, int sum, int count) {
//     if(ind == arr.size()) {
//         if(sum == 3) {
//             return count + 1;
//         }
//         return count;
//     }
//     if(sum > 3) return count;

//     seq.push_back(arr.at(ind));
//     sum += arr.at(ind);
//     count += get_count(arr, seq, ind+1, sum, count);

//     sum -= arr.at(ind);
//     seq.pop_back();
//     count += get_count(arr, seq, ind+1, sum, count);
//     return count;
// }

// Print no of subsequence whoes sum : 
int get_count(vector<int> arr, int ind, int sum) {
    if(sum > 3) return 0;
    
    if(ind == arr.size()) {
        if(sum == 3)
            return 1;
        return 0;
    }

    sum += arr.at(ind);
    int l = get_count(arr, ind+1, sum);
    sum -= arr.at(ind);
    int r= get_count(arr, ind+1, sum);
    return l + r;
}


int main()
{
    vector<int> arr = {3, 1, 2, 1};
    vector<int> sub = {};
    cout<<"Array is = \n";
    display(arr);

    cout<<"Subsequence are : \n";
    sub_sequence(arr, sub, 0);

    cout<<"Sequnce whoes sum is 3: \n";
    sum_sequence(arr, sub, 0, 0);

    cout<<"any one subsequence whoes sum is 3: \n";
    if(any_one_subsequence(arr, sub, 0, 0)) {}

    cout<<"no of subsequence whoes sum is 3: \n";
    cout<<get_count(arr, 0, 0)<<endl;
    return 0;
}