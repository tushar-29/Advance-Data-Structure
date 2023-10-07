#include<bits/stdc++.h>
using namespace std;

void display(array<int, 5> arr) {
    for(auto i=arr.begin(); i != arr.end(); i++)
        cout<<*i<<"  ";
    cout<<endl;
}

bool check_pallondrome(string arr, int i, int n) {
    if(i >= n / 2)
        return true;
    if(arr.at(i) != arr.at(n-i-1))
        return false;
    return check_pallondrome(arr, i+1, n);
}

int main()
{
    string name = "madddam";
    cout<<check_pallondrome(name, 0, name.size())<<endl;
    return 0;
}