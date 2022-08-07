// DEQUEUE IS SIMILEAR TO VECTOR 
// INSERTION AND DELETION AT BEG OR LAST TAKE O(1) time
// INSERTION AND DELETION AT OTHER POS TAKE O(n)


#include<bits/stdc++.h>
using namespace std;

void display(deque<int> dq){
    for(auto i: dq){
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

    deque<int> dq;
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);
    display(dq);

    dq.push_back(200);
    dq.push_back(300);
    dq.push_back(400);
    display(dq);

    dq.pop_back();
    display(dq);

    dq.pop_front();
    display(dq);

    return 0;
}