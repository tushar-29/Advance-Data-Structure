/*
Forg Jump Problem
Here we take the forg to jump from 1st stair to nth stair. 
Each stair has certain energy which difference of energy of that two stair
Find the possible path that take minimum energy to reach nth stair.

*/


#include<bits/stdc++.h>
using namespace std;


void frogJump_recc(int energy[], int ptr, int min, int &old_min,
vector<int> sol, vector<vector<int>> &ans) {

    if(ptr == 1) {
        if(min < old_min) {
            ans.clear();
            old_min = min;
            ans.push_back(sol);
        }
        else if(min == old_min)
            ans.push_back(sol);
        return;
    }

    min += abs(energy[ptr-1] - energy[ptr-2]);
    sol.push_back(ptr-1);
    frogJump_recc(energy, ptr-1, min, old_min, sol, ans);
    min -= abs(energy[ptr-1] - energy[ptr-2]);
    sol.pop_back();

    if(ptr - 2 >= 1) {
        min += abs(energy[ptr-1] - energy[ptr-3]);
        sol.push_back(ptr-2);
        frogJump_recc(energy, ptr-2, min, old_min, sol, ans);
        min -= abs(energy[ptr-1] - energy[ptr-3]);
        sol.pop_back();
    }
}

int frogJump_recc2(int step, int energy[]) {
    if(step == 1)
        return 0;
    

    int right = INT_MAX;
    int left = frogJump_recc2(step-1, energy) + abs(energy[step-1] - energy[step-2]);

    if(step - 2 >= 1)
        right = frogJump_recc2(step-2, energy) + abs(energy[step-1] - energy[step-3]);

    return (left < right ? left : right); 
}


int frogJump_memo(int step, int energy[], vector<int> &gap) {
    if(step == 1) {
        return 0;
    }

    if(gap[step -1] == -1)
        gap[step-1] = frogJump_memo(step-1, energy, gap);

    int left = gap[step-1] + abs(energy[step-1] - energy[step-2]);         
    
    if(step - 2 >= 1) {
        if(gap[step - 2] == -1)
            gap[step-2] = frogJump_memo(step-2, energy, gap);
        
        int right = gap[step-2] + abs(energy[step-1] - energy[step-3]);

        return left < right ? left : right;
    }

    return left; 
}

int frogJump_memo2(int step, int energy[], vector<int> &gap) {
    if(step == 0) 
        return 0;
    

    if(gap[step] != -1)
        return gap[step];

    int left = frogJump_memo2(step-1, energy, gap) + abs(energy[step] - energy[step-1]);         
    int right = INT_MAX;

    if(step > 1) 
        right = frogJump_memo2(step-2, energy, gap) + abs(energy[step] - energy[step-2]);
    
    return gap[step] = min(right, left); 
}


int frogJump_tabu(int step, int energy[]) {
    if(step == 0)
        return 0;
    
    int a=0; // gap[i-1]
    int b=0; // gap[i-2]
    int left=0, right=INT_MAX;
    for(int i=1; i<=step; i++) {
        left = a + abs(energy[i] - energy[i-1]);
        if(i > 1)
            right = b + abs(energy[i] - energy[i-2]);

        b = a;
        a = min(left, right); // gap[i] = min(...)
    }
    return a; // return gap[i-1]
}


void Main(int step, int energy[]) {
    vector<int> sol;
    vector<vector<int>> ans;
    int min=0, old_min=INT_MAX;

    sol.push_back(step);
    frogJump_recc(energy, step, min, old_min, sol, ans);

    for(auto arr: ans) {
        cout<<"[ ";
        for(auto i: arr)
            cout<<i<<" ";
        cout<<"]\n";
    }

    cout<<"Minimum energy required = "<<old_min<<endl;

    cout<<"Minimum energy required = "<<frogJump_recc2(step, energy)<<endl;

    vector<int> gap(step, -1);
    cout<<"Minimum energy required = "<<frogJump_memo(step, energy, gap)<<endl;

    vector<int> gap2(step, -1);
    cout<<"Minimum energy required = "<<frogJump_memo2(step-1, energy, gap2)<<endl;

    cout<<"Minimum energy required = "<<frogJump_tabu(step-1, energy)<<endl;
}


int main()
{
    int step=6;
    int energy[] ={30, 10, 20, 10, 70, 50};

    Main(step, energy);

    return 0;
}