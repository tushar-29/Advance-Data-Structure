#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // vector remove the problem of decleration of size
    // 10^6 is max size of arr int, double in c++ inside int main() function.
    // 10^7 is max size of arr int, double in c++ declared globally.
    // 10^7 for bool type inside int main() and 10^8 globally. 

    vector<int> arr; // {}
    cout<<arr.size()<<endl; // => 0

    //NOTE:push_back() and emplace_back() append element but emplace_back take less time. 
    arr.push_back(10); // {10} append the element
    arr.push_back(20); // {10, 20} 
    cout<<arr.size()<<endl; // => 2

    arr.pop_back(); // => {10} delete last element
    cout<<arr.size()<<endl;

    arr.clear(); // => {} empty the array
    cout<<arr.size()<<endl;

    //declare size of vector with initilization
    vector<int> arr1(5, 0); // size 10 with all element to 0 is created.

    // size 10 with all element to 10 is created.
     vector<int> arr2(3, 7); // {7, 7, 7}
    // size is 5 now but still can be increase by push back

    // insert all element of one vector in a new vector
    vector<int> arr3(arr2.begin(), arr2.end()); // end is address[last_element + 1] 

    // swap(vector 1, vector 2)
    for(auto it: arr1)
        cout<<it<<"  ";
    cout<<endl;

    for(auto it: arr2)
        cout<<it<<"  ";
    cout<<endl;

    swap(arr1, arr2);

    for(auto it: arr1)
        cout<<it<<"  ";
    cout<<endl;

    for(auto it: arr2)
        cout<<it<<"  ";
    cout<<endl;


    // 2D vectors
    vector<vector<int>> matrix;

    vector<int> arr4;
    arr4.push_back(10);
    arr4.push_back(20);

    vector<int> arr5;
    arr5.push_back(100);
    arr5.push_back(200);
    arr5.push_back(300);

    matrix.push_back(arr4);
    matrix.push_back(arr5);

    // it will have dynamic row for each insertion
    cout<<"\nMATRIX"<<endl;
    for(auto i: matrix){
        for(auto j: i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }

    // II'nd method
    for(auto i=matrix.begin(); i<matrix.end(); i++){
        for(auto j=(*i).begin(); j<(*i).end(); j++){
            cout<<*j<<"  ";
        }
        cout<<endl;
    }

    // III'rd method
    for(auto i=0; i<matrix.size(); i++){
        for(auto j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }

    

    // Pre define a  matrix
    vector<vector<int>> matrix1(10, vector<int> (20, 2));
    matrix1.push_back(vector<int>(5, 10));
    cout<<"\nMATRIX 2"<<endl;
    for(auto i=0; i<matrix1.size(); i++){
        for(auto j=0; j<matrix1[i].size(); j++){
            cout<<matrix1[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    // here 10 X 20 matrix is generated with all element as 2

    // array of vectors
    vector<int> arr6[4]; // [{}, {}, {}, {}]
    
    return 0;
}