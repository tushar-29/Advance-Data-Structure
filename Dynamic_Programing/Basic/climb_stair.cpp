/*
Problem is to find all possible solution for stair jump poblem
Here a person has to go form 0th stair to nth stair with step size 1 or 2 at a time
eg: 
n = 3
Possible solutions : 
0 to 1, 1 to 2, 2 to 3 => {1, 1, 1}
0 to 2, 2 to 2 => {2, 1}
0 ot 1, 1 to 3 => {1, 2}

step 1) For represention it in term of index :  
    Taking the nth step as indexes.

step 2) Do all posible stuff on that index :
    Trying to jump with step size 1 and 2 for that index

*/


#include<bits/stdc++.h>
using namespace std;


void stairJump(int step, vector<int> solution, vector<vector<int>> &ans) {
    if(step < 0) return;

    if(step == 0) {
        ans.push_back(solution);
        return;
    }
    solution.push_back(1);
    stairJump(step-1, solution, ans);
    solution.pop_back();

    solution.push_back(2);
    stairJump(step-2, solution, ans);
    solution.pop_back();
}


int countStairJump_recc(int step) {
    if(step == 1 || step == 0)
        return 1;

    return countStairJump_recc(step-1) + countStairJump_recc(step-2);
}


int countStairJump_memo(int step) {
    if(step == 1)
        return 1;

    vector<int> arr(step+1, 0);
    arr[0] = 1;
    arr[1] = 1;

    for(int i=2; i<=step; i++)
        arr[i] = arr[i-1] + arr[i-2];
    
    return arr[step];
}


int countStairJump_tabu(int step) {
    if(step == 1)
        return 1;

    int a=1, b=1, c=0;

    for(int i=2; i<=step; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}


void Main(int step) {
    if(step == 0) {
        cout<<"No jump required\n";
        return;
    }

    vector<int> solution;
    vector<vector<int>> ans;
    stairJump(step, solution, ans);

    for(auto arr: ans) {
        cout<<"[ ";
        for(auto i : arr) 
            cout<<i<<" ";
        cout<<"]\n";
    }

    cout<<"Step count = "<<countStairJump_recc(step)<<endl;
    cout<<"Step count = "<<countStairJump_memo(step)<<endl;
    cout<<"Step count = "<<countStairJump_tabu(step)<<endl;
}


int main()
{
    int step=5;

    Main(step);

    return 0;
}