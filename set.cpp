// SET balanced tree structure WHICK MAY BE RED BLACK TREE
// TIME TAKEN IS O(log n)

// UNORDERED SET take O(1) for best case and O(n) worst case

#include<bits/stdc++.h>
using namespace std;

// unordered_set<int> st; random order but unique 
// multiset<int> st; order but store duplicate 
                    // .erase() will erase all occurance
                    // .find() will retun first occurance pointer

void display(set<int> st){
    for(auto i=st.begin(); i != st.end(); i++)
        cout<<*i<<", ";
    cout<<endl;
}
// how to use custom class as in set how it will compare.

int main()
{
    // take unique elements and its inserted in sorted order
    // cant be access by bracket indexing

    // unordered_set<int> st; random order but unique 

    // .insert(value) take log(n) time  or can be use st.emplace(value);
    set<int> st;
    int n = 5;
    for(int i=0; i<n; i++)
        st.insert(n-i);
 
    display(st);
    set<int> st1 = {5, 8, 3, 9, 1, 6};
    display(st1);

    // .erase(pointer/value) : erase the value/given pointer
    cout<<"\n\nErase : "<<endl;
    st.erase(st.begin());
 
    display(st);
    auto it1 = st.begin();
    it1++;
    st.erase(++it1, st.end());
    display(st);

    st.erase(2);
    display(st);

    // .find(value_to_find) : return iterator pointer pointing that value
    // else return pointer .end()
    cout<<"\n\nFIND : \n";
    set<int> st2 = {8, 7, 6, 5, 4, 3, 2, 1};
    display(st2);
    cout<<"return pointer "<<*(st2.find(2))<<endl;
    cout<<"DEL 4, 5, 6"<<endl;
    auto it2 = st2.find(4);
    auto it3 = st2.find(6);
    st2.erase(it2, ++it3);
    display(st2);

    // count() find how many times the instance occures

    cout<<"OCCURANCE OF TIME"<<st2.count(2);

    return 0;  
}