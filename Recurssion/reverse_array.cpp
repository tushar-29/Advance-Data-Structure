#include<bits/stdc++.h>
using namespace std;

// Pass by value
void display(array<int, 5> arr) {
    for(auto i=arr.begin(); i != arr.end(); i++)
        cout<<*i<<"  ";
    cout<<endl;
}

void swap_value(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_1(array<int, 5> *arr, int i, int j) {
    if(i >= j)
        return;
    swap_value(&(arr->at(i)), &(arr->at(j)));
    reverse_1(arr, i+1, j-1);
}

void reverse_2(array<int, 5> *arr, int i, int n) {
    if(i >= n / 2)
        return;
    swap_value(&(arr->at(i)), &(arr->at(n-i-1)));
    reverse_2(arr, i+1, n);
}

int main()
{
    array<int, 5> arr = {10, 20, 30, 40, 50};
    display(arr);
    reverse_1(&arr, 0, arr.size()-1);
    display(arr);

    reverse_2(&arr, 0, arr.size());
    display(arr);

    // swap() pre-built can also been used to do this
    int a=100, b=200;
    cout<<a<<"  "<<b<<endl;
    swap(a, b);
    cout<<a<<"  "<<b<<endl;

    return 0;
}