#include<bits/stdc++.h>
using namespace std;

void display(priority_queue<int> pq) {
    while(!pq.empty()){
        cout<<pq.top()<<", ";
        pq.pop();
    }
    cout<<endl;
}

int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(2);
    pq.push(7);
    pq.push(3);
    pq.push(4);

    display(pq);

    priority_queue<pair<int, int>> pq1;
    pq1.push({2, 7});
    pq1.push({3, 6});
    pq1.push({1, 4});
    pq1.push({7, 2});
    pq1.push({2, 3});
    pq1.push({9, 1});
    pq1.push({6, 9});

    while(!pq1.empty()){
        cout<<"("<<pq1.top().first<<", "<<pq1.top().second<<"), ";
        pq1.pop();
    }
    cout<<endl;


    cout<<"MIN HEAP PRIORITY QUEUE"<<endl;
    // grater<int> is comparator bring smallest at first
    // minimum pariority queue 
    priority_queue<int, vector<int>, greater<int>> pq2; 
    pq2.push(5);
    pq2.push(7);
    pq2.push(2);
    pq2.push(9);
    pq2.push(1);
    pq2.push(4);
    pq2.push(6);

    while(!pq2.empty()){
        cout<<pq2.top()<<", ";
        pq2.pop();
    }
    cout<<endl;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq3;
    pq3.push({2, 7});
    pq3.push({3, 6});
    pq3.push({1, 4});
    pq3.push({7, 2});
    pq3.push({2, 3});
    pq3.push({9, 1});
    pq3.push({6, 9});

    while(!pq3.empty()){
        cout<<"("<<pq3.top().first<<", "<<pq3.top().second<<"), ";
        pq3.pop();
    }
    cout<<endl;

    return 0;
}