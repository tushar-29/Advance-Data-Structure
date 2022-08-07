//  MAP IMPLEMENT Red-Black Tree
// MAP TAKE TIME O(log n)

// UNORDERED_MAP TAKE O(1) for best case and O(n) in worst case


#include<bits/stdc++.h>
using namespace std;

void display(map<string, int> mpp) { 
    for(auto i=mpp.begin(); i != mpp.end(); i++){
        cout<<(*i).first<<" : "<<(*i).second<<endl;
    }
    cout<<endl;
}


int main() {

    // map take log(n) time store in sorted order
    // key are unique but value can be same

    // unordered_map<string, int> mpp; take O(1) in best and O(n) in worst
    // store in any rando order

    // multimap<string, int> mpp; store orderd multiple duplicate key

    map<string, int> mpp;
    mpp["TUSHAR"] = 216;
    mpp["SHASHI"] = 248;
    mpp["JAI"] = 206;
    mpp.emplace("TANISHQ", 186);

    display(mpp);

    mpp.erase("TUSHAR");
    display(mpp);

    mpp.erase(mpp.begin());
    display(mpp);

    // mpp.erase(mpp.find("TUSHAR"), mpp.find("JAI"));
    // display(mpp);

    // (it) is pointer containing pair<auto first, auto second>
    auto it = mpp.find("SHASHI"); // (it) is pointer containing 
    cout<<"SHASHI POINTER = "<<(*it).first<<" : "<<(*it).second<<endl; 
    // arrow function can also be used `->` insted of `(* ).`

    bool flag = mpp.empty(); // => 0 if false 1 if true
    cout<<"IS EMPTY = "<<flag<<endl;

    bool flag2 = mpp.count("TUSHAR"); // => 1 if exist
    cout<<"IS TUSHAR THERE = "<<flag2<<endl;

    display(mpp);

    auto it3 = mpp.find("SHASHI");
    cout<<mpp.erase("SHASHI")<<endl;
    display(mpp);

    // cout<<"\nSHASHI it3 = "<<*it3<<endl; //=> ERROR

    // now shashi is not in mpp so as it3




    return 0;
}