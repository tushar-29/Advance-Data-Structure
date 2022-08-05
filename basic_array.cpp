/*

NOTE: USE bits/stdc++.h only when for CP it bring all prequired liberiary at one go
But in iterview we should not use it since a company needs specific solution and 
limitied and required module should be used for only for that problem only.

*/

#include<bits/stdc++.h>
using namespace std;

namespace tushar {
    int val = 100;

    int sum(int a, int b){
        return a+b+val; // val of tushar is used
    }
}

int main()
{
    int val = 50;
    // Here std is already in using as `std::cout` by using ->using namespace std;
    cout << val<<endl;;  // => 50
    cout << tushar::val<<endl; // => 100
    cout<<tushar::sum(val, tushar::val)<<endl; //=> 250


    cout<<"\n\nARRAY"<<endl;
    array<int, 5> arr; // => {?, ?, ?} But global decleration will give 0, 0, ...
    array<int, 5> arr1 = {1, 4, 6};  // => {1, 4, 6, 0, 0, 0}
    array<int, 5> arr2 = {0};  // => {0, 0, 0, 0 ,0}
    array<int , 5> arr3 = {1}; // => {1, 0, 0, 0, 0}
    array<int, 5> arr4;
    arr4.fill(5); //=> {5, 5, 5, 5, 5}

    for(int i=0; i<5; i++)
        cout<<arr.at(i)<<"  ";
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<arr1.at(i)<<"  ";
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<arr2.at(i)<<"  ";
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<arr3.at(i)<<"  ";
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<arr4.at(i)<<"  ";
    cout<<endl;


    cout <<"\n\nIterators"<<endl;
    // begin() : return address of 1st element in the array
    // end() : return address of = address[last element] + sizeof(one_element) 
    // rbegin() :  return address of last element
    // rend() : return address of = address[first_element] - sizeof(one_element)

    array<int, 5> arr5 = {0};
    for(int i=0; i<5; i++) {
        arr5.at(i) = i+10;
    } 

    for (auto it=arr5.begin(); it != arr5.end(); it++) {
        cout<<it<<"  "; // => {address1, address2, address3, address4, address5}
    }
    cout<<endl;
    for (auto it=arr5.begin(); it != arr5.end(); it++) {
        cout<<*it<<"  "; // => {10, 11, 12, 13, 14}
    }
    cout<<endl;
    for (auto it: arr5) {
        cout<<it<<"  ";
    }
    cout<<endl;

    // reverse printing
    for (auto it=arr5.rbegin(); it != arr5.rend(); it++) {
        cout<<*it<<"  "; // => {14, 13, 12, 11, 10}
    }
    cout<<endl;
    
    for (auto it=arr5.end()-1; it >= arr5.begin(); it--) {
        cout<<*it<<"  "; // => {14, 13, 12, 11, 10}
    }
    cout<<endl;

    string st = "Tushar Prasad";
    for(auto i : st)
        cout<<i<<", "; // => T, u, s, h, a, r,  , P, r, a, s, a, d,  
    cout<<endl;


    array<int, 5> arr6 = {1, 2, 3};

    // size of array
    cout<<"Size = "<<arr6.size()<<endl; // => size = 5

    // print first element
    cout<<"Front = "<<arr6.front()<<endl; // => front = 1

    // print last element --> if arr has not included still print last element as 0
    cout<<"Back = "<<arr6.back()<<endl; // => back = 0
    
    
    return 0;
}