// LIST IS SIMILEAR TO VECTOR 
// INSERTION AND DELETION AT BEG OR LAST TAKE O(1) time
// DELETION AT OTHER POS TAKE O(1)


#include<bits/stdc++.h>
using namespace std;

void display(list<int> ls){
    for(auto i: ls){
        cout<<i<<", ";
    }
    cout<<endl;
}


int main()
{
    // push_fornt(), push_back()
    // pop_fornt(), pop_back()
    // empty(), at()
    // .begin(), .end(), .rbegin(), .rend()
    // .size(), .clear()
    // .remove() take O(1)

    list<int> ls;
    ls.push_front(20);
    ls.push_front(30);
    ls.push_front(40);
    display(ls);

    ls.push_back(200);
    ls.push_back(300);
    ls.push_back(400);
    display(ls);

    ls.pop_back();
    display(ls);

    ls.pop_front();
    display(ls);

    ls.remove(300);
    display(ls);

    return 0;
}