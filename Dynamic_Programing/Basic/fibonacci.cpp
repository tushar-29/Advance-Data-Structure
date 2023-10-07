#include<bits/stdc++.h>
using namespace std;

// Memonization button up approch
// taking 0 of fibonacci series as 1st term then 1 of fibonaci series as 2nd term.
int fibonacci(int term, vector<int> &arr) {
    if(term <= 2) {
        return term-1;
    }
    if(arr[term] != -1)
        return arr[term];

    arr[term] = fibonacci(term-1, arr) + fibonacci(term-2, arr);
    return arr[term];
    
}

// Tabulation Approch
int fibonacci_tab(int term) {
    if(term <= 2)
        return term-1;
    
    vector<int> arr(term+1, -1);
    arr[1] = 0;
    arr[2] = 1;
    
    for(int i=3; i<=term; i++) 
        arr[i] = arr[i-1] + arr[i-2];

    return arr[term];
}


int fibonacci_sim(int term) {
    if(term <= 2)
        return term-1;
    
    int a=0, b=1, c=-1;
    for(int i=3; i<=term; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;

}


void Main(int term) {
    if(term == 0)
        return;

    vector<int> arr(term+1, -1);
    int e = fibonacci(term, arr);
    int e1 = fibonacci_tab(term);
    int e2 = fibonacci_sim(term);
    cout<<term<<" no. term in fibonacci series is = "<<e<<endl;
    cout<<term<<" no. term in fibonacci series is = "<<e1<<endl;
    cout<<term<<" no. term in fibonacci series is = "<<e2<<endl;
}



int main()
{
    int term=0;

    Main(term);

    return 0;
}