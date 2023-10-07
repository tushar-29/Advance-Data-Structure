#include<bits/stdc++.h>
using namespace std;

// Time Complex will be about O(2^n) expontential time
int fibonacci(int n) {
    if(n <= 1)
        return n;
    return(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    cout<<fibonacci(10);
    return 0;
}
