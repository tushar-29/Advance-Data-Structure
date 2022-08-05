#include<iostream>
#include<algorithm>
#include<numeric> // for accumulate()
using namespace std;

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

int check(int i){return i%2;}

void print_result(int i)
{
    cout<<"\t"<<i;
}



int main()
{
    int a[] = {7, 9, 5, 1, 7, 3};
    int size = sizeof(a) / sizeof(int);

    cout<<"Normal array :\t";
    display(a, size);

    // sort(starting_address, end_address)
    sort(a, a+size);
    cout<<"sorted array :\t";
    display(a, size);

    // reverse(starting_address, end_address)
    reverse(a, a+size);
    cout<<"reverse array :\t";
    display(a, size);

    // *min_element(starting_address, end_address)
    cout<<"Min element : "<<*min_element(a, a+size)<<endl;
    // *max_element(starting_address, end_address)
    cout<<"Max element : "<<*max_element(a, a+size)<<endl;

    // count(starting_address, end_address, variable_to_count)
    cout<<"occurance of 7 : "<<count(a, a+size, 7)<<endl;

    // find(starting_address, end_address, variable_to_find)
    // if found turn 1 else return last element address
    cout<<"occurance of 11: \n";
    if(find(a, a+size, 11) != a+size)
        cout<<"Element found\n";
    else
        cout<<"Not present\n";

    // accumulate(starting_address, end_address, inital_sum_value)
    cout<<"sum = "<<accumulate(a, a+size, 0)<<endl;

    // all_of(start_add, end_add, lamda function)
    // check for all true
    if(all_of(a, a+size, [](int i){return i%2;}))
        cout<<"all element are odd\n";
    else
        cout<<"not all element are odd\n";

    // any_of(start_add, end_add, lamda function)
    // check for all false
    if(any_of(a, a+size, [](int i){return i<0;}))
        cout<<"there is negative element\n";
    else
        cout<<"no negative element\n";

    // none_of(start_add, end_add, lamda function)
    // check for all false
    if(none_of(a, a+size, [](int i){return i<0;}))
        cout<<"there is negative element\n";
    else
        cout<<"no negative element\n";


    // for each 
    for_each(a, a+size, print_result);
    cout<<endl;


    return 0;
}