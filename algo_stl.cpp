#include<bits/stdc++.h>
using namespace std;



int main()
{
    // sort(starting_pointer, ending_pointer, comparator);
    // comarator is optional
    cout<<"SORT : "<<endl;
    int arr[5] = {10, 5, 8, 2, 20};
    sort(arr, arr+5);
    
    for(int i=0; i<5; i++)
        cout<<arr[i]<<", ";
    cout<<endl;

    vector<int> arr1 = {4, 7, 2, 8, 1, 3};
    sort(arr1.begin(), arr1.end());

    for(auto i: arr1)
        cout<<i<<", ";
    cout<<endl;

    // sorting till specific index
    vector<int> arr2 = {40, 70, 20, 80, 10, 30};
    sort(arr2.begin(), arr2.end() - 2);

    for(auto i: arr2)
        cout<<i<<", ";
    cout<<endl;
// -----------------------------------------------------------------

    // reverse(starting_pointer, ending_pointer)
    
    cout<<"\nREVERSE : "<<endl;
    int arr3[5] = {1, 2, 3, 4, 5};
    reverse(arr3, arr3+5);
    
    for(int i=0; i<5; i++)
        cout<<arr3[i]<<", ";
    cout<<endl;

    vector<int> arr4 = {10, 20, 30, 40, 50};
    reverse(arr4.begin(), arr4.end());

    for(auto i: arr4)
        cout<<i<<", ";
    cout<<endl;

    // reversing till specific index
    vector<int> arr5 = {10, 20, 30, 40, 50};
    reverse(arr5.begin(), arr5.end() - 2);

    for(auto i: arr5)
        cout<<i<<", ";
    cout<<endl;

    // --------------------------------------------------------------

    // max_element(starting_pointer, ending_pointer)
    // return address of max element's pointer
    cout<<"\n FIND MAIXIMUM : "<<endl;
    int arr6[5] = {1, 2, 3, 4, 5};
    cout<<"MAX = "<<*max_element(arr6, arr6+5)<<endl;
    
    vector<int> arr7 = {10, 20, 30, 40, 50};
    cout<<"MAX = "<<*max_element(arr7.begin(), arr7.end())<<endl;

    vector<int> arr8 = {10, 20, 30, 40, 50};
    cout<<"MAX = "<<*max_element(arr7.begin(), arr7.end()-2)<<endl;

// ----------------------------------------------------------------------

    // min_element(starting_pointer, ending_pointer)
    // return address of minimum element's pointer
    cout<<"\n FIND MINIMUM : "<<endl;
    int arr9[5] = {1, 2, 3, 4, 5};
    cout<<"MIN = "<<*min_element(arr9, arr9+5)<<endl;
    
    vector<int> arr10 = {10, 20, 30, 40, 50};
    cout<<"MIN = "<<*min_element(arr10.begin(), arr10.end())<<endl;

    vector<int> arr11 = {10, 20, 30, 40, 50};
    cout<<"MIN = "<<*min_element(arr11.begin()+3, arr11.end())<<endl;

// ----------------------------------------------------------------------

    // accmulartor(strarting_pointer, ending_pointer, initial_value)
    // return sum element 
    cout<<"\nACCMULATOR OR SUM : "<<endl;

    vector<int> arr12 = {10, 20, 30, 40, 50};
    cout<<"SUM = "<<accumulate(arr11.begin(), arr11.end(), 0)<<endl;
    cout<<"SUM = "<<accumulate(arr11.begin(), arr11.end(), 10)<<endl;
    cout<<"SUM = "<<accumulate(arr11.begin(), arr11.end()-1, 0)<<endl;

// ------------------------------------------------------------------------

    // count(starting_pointer, ending_pointer, element_to_count)
    // return no of occurance of that element
    // return 0 if element does not occure 

    cout<<"\nCOUNT or FIND NO. OF OCCURANCE : "<<endl;
    vector<int> arr13 = {7, 1, 2, 2, 3, 6, 4, 2, 5, 6, 2};
    cout<<"COUNT 2 OCCURANCE : "<<count(arr13.begin(), arr13.end(), 2)<<endl;
    cout<<"COUNT 10 OCCURANCE : "<<count(arr13.begin(), arr13.end(), 10)<<endl;
    
// --------------------------------------------------------------------------

    // find(staring_pointer, ending_pointer, element_to_find)
    // return pointer pointing to searched element
    // else return end() pointer if element does not occure

    // index of that element can be taken by subtraction
    // index = .find(...) - .begin()

    cout<<"\nFIND FIRST OCCURANCE OF ELEMNT:"<<endl;
    vector<int> arr14 = {7, 1, 2, 2, 3, 6, 4, 2, 5, 6, 2};
    cout<<"FIND 2 OCCURANCE : "<<find(arr14.begin(), arr14.end(), 10) - (arr14.end()+1)<<endl;
    cout<<"FIND 7 OCCURANCE : "<<find(arr14.begin(), arr14.end(), 7) - arr14.begin()<<endl;
    cout<<"FIND 7 OCCURANCE : "<<*find(arr14.begin(), arr14.end(), 7)<<endl;

    // 10 does not occure
    auto ind = find(arr14.begin(), arr14.end(), 10);
    ind == arr14.end() ? cout<<"10 DOES NOT EXIST" : cout<<"10 EXIST";
    cout<<endl;

// -------------------------------------------------------------------------

    // binary_search(staring_pointer, ending_pointer, searched_no)
    // works only of sorted array
    // return true or falese for searched number

    cout<<"BINARY SEARCH : "<<endl;
    vector<int> arr15 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<"SEARCH 5 = "<<binary_search(arr15.begin(), arr15.end(), 5)<<endl;
    cout<<"SEARCH 11 = "<<binary_search(arr15.begin(), arr15.end(), 11)<<endl;

// --------------------------------------------------------------------------

    // lower_bound(staritng_pointer, ending_pointer, less_then_element)
    // works only in sorted array.
    // return the pointer pointing to element which is (not less then the element pass)
    // or equal to the element pass.

    cout<<"LOWER BOUND : "<<endl;
    vector<int> arr16 = {1, 2, 3, 4, 4, 4, 6, 7, 8, 9, 9};
    //  6 is the element which is !< 5 in the array
    cout<<"LOWER BOUND 5 = "<<*(lower_bound(arr16.begin(), arr16.end(), 5))<<endl;
    cout<<"LOWER BOUND 4 = "<<*(lower_bound(arr16.begin(), arr16.end(), 4))<<endl;
    //  no element is  !< 10 in the array so it return end pointer
    cout<<"LOWER BOUND 10 = "<<*(lower_bound(arr16.begin(), arr16.end(), 10))<<endl;
    
// ---------------------------------------------------------------------------------

    // upper_bound(staritng_pointer, ending_pointer, less_then_element)
    // works only in sorted array.
    // return the pointer pointing to element which is which is just greater the element 
    // pass.

    cout<<"UPPER BOUND : "<<endl;
    vector<int> arr17 = {1, 2, 3, 4, 4, 4, 6, 7, 8, 9, 9};
    //  6 is the element which is !< 5 in the array
    cout<<"UPPER BOUND 5 = "<<*(upper_bound(arr17.begin(), arr17.end(), 5))<<endl;
    cout<<"UPPER BOUND 4 = "<<*(upper_bound(arr17.begin(), arr17.end(), 4))<<endl;
    //  no element is  !< 10 in the array so it return end pointer
    cout<<"UPPER BOUND 10 = "<<*(upper_bound(arr17.begin(), arr17.end(), 10))<<endl;

// ----------------------------------------------------------------------------------

    //  next_permutation(starting_pointer, ending_pointer)
    // return bool value and also change the string to its sorted next 
    // permutation

    string s = "cba";

    sort(s.begin(), s.end());
    do{
        cout<<s<<",  ";
    }while(next_permutation(s.begin(), s.end()));

    return 0;
 

}