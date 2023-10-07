#include<bits/stdc++.h>
using namespace std;


int frogJumpK_recc(int step, int energy[], int k) {
    if(step == 0)
        return 0;
    
    int get_min=INT_MAX, temp=0;
    for(int i=1; (i<=k && step-i >=0); i++) {
        temp = frogJumpK_recc(step-i, energy, k) + abs(energy[step] - energy[step-i]);
        if(temp < get_min)
            get_min = temp;
    }
    return get_min;
}


int frogJumpK_memo(int step, int energy[], int k, vector<int> &arr) {
    if(step == 0)
        return 0;
    
    if(arr[step] != -1)
        return arr[step];
    
    int get_min=INT_MAX, temp=0;
    for(int i=1; (i<=k && step-i >=0); i++) {
        temp = frogJumpK_recc(step-i, energy, k) + abs(energy[step] - energy[step-i]);
        if(temp < get_min)
            get_min = temp;
    }
    return arr[step] = get_min;
}


int frogJumpK_tabu(int step, int energy[], int k) {

    int arr[step+1] = {0};
    int i=0, j=0, get_min=0, temp=0;
    

    for(j=1; j<=step; j++) {
        get_min=INT_MAX;
        temp=0;
        for(i=1; (i<=k && j-i >=0); i++) {
            temp = arr[j-i] + abs(energy[j] - energy[j-i]);
            if(temp < get_min)
                get_min = temp;
        }
        arr[j] = get_min;
    }
    return arr[j-1];
}


void Main(int step, int energy[], int k) {
    cout<<frogJumpK_recc(step-1, energy, k)<<endl;

    vector<int> arr(step, -1);
    cout<<frogJumpK_memo(step-1, energy, k, arr)<<endl;

    cout<<frogJumpK_tabu(step-1, energy, k)<<endl;
}


int main()
{
    int step=6, k=3;
    int  energy[] = {30, 10, 60, 10, 50, 20};

    Main(step, energy, k);

    return 0;
}