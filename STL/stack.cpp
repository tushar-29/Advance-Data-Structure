#include<bits/stdc++.h>
using namespace std;

// PASS BY REFERENCE (stack<int> &st) 
// PASS BY VALUE (stack<int> st)
void display(stack<int> st) {
    cout<<"Display"<<endl;

    while(!st.empty()){
        cout<<st.top()<<"  ";
        st.pop();
    }
    cout<<endl;
}

int main() {

    // LIFO
    stack<int> st;

    for(int i=10; i<101; i+=10){
        st.push(i);
    }
    
    // NOTE IS STACK IS EMPTY THEN st.top() WILL GIVE ERROR
    cout<<"STACK SIZE = "<<st.size()<<endl;
    cout<<"STACK TOP = "<<st.top()<<endl;
    display(st);
    display(st);


    return 0;
}