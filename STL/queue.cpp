#include<bits/stdc++.h>
using namespace std;

void display(queue<int> q){
    // cout<<"DISPLAY BY BACK : ";
    // while(!q.empty()){
    //     cout<<q.back()<<"  ";   //=> 100 100 100 100 100 100 100 100 100 100
    //     q.pop();
    // }
    // cout<<endl;

    cout<<"DISPLAY BY FRONT : ";
    while(!q.empty()){
        cout<<q.front()<<"  ";  //=> 10 20 30 40 50 60 70 80 90 100
        q.pop();
    }
    cout<<endl;

    
}

int main() {

    // FIFO
    queue<int> q;
    for(int i=10; i<101; i+=10)
        q.push(i);
    
    cout<<"QUEUE SIZE = "<<q.size()<<endl;
    cout<<"QUEUE FRONT  = "<<q.front()<<endl;
    cout<<"QUEUE BACK  = "<<q.back()<<endl;

    display(q);

    return 0;
}