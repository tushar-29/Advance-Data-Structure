#include<bits/stdc++.h>
using namespace std;



int main()
{
    bitset<5> bt;
    // her bt has 5 bit space whick take 1 and 0 only of bool type

    bt = 31; // => 11111
    cout<<"31 = "<<bt<<endl;

    // ALL check weather all bit is 1 or not
    // ANY check weather any one bit is 1 or not
    cout<<"ALL = "<<bt.all()<<endl;
    cout<<"ANY = "<<bt.any()<<endl;

    bitset<5> bt1 = 0; // => 00000
    cout<<"0 = "<<bt1<<endl;

    cout<<"ALL = "<<bt1.all()<<endl;
    cout<<"ANY = "<<bt1.any()<<endl;

    bitset<5> bt2 = 20; // => 10100
    cout<<"20 = "<<bt2<<endl;

    cout<<"ALL = "<<bt2.all()<<endl;
    cout<<"ANY = "<<bt2.any()<<endl;


    // COUNT NO IF 1 in bitset
    cout<<"COUNT for 31= "<<bt.count()<<endl;
    cout<<"COUNT for 0= "<<bt1.count()<<endl;
    cout<<"COUNT for 20= "<<bt2.count()<<endl;

    // FLIP(index) index it form right side (not as array)
    // .filp() will flip all
    bitset<5> bt3 = 20; // => 10100
    cout<<"20 = "<<bt3<<endl;
    bt3.flip(3);
    cout<<"FLIP index 3 = "<<bt3<<endl; 

    // .none() check if all are 0's
    cout<<"NONE in 20 = "<<bt3.none()<<endl;
    cout<<"NONE in 0 = "<<bt1.none()<<endl;
    

    // .set() FILL ALL POSITION BY 1
    bt1.set();
    cout<<"SET in 00000 = "<<bt1<<endl;

    bt3.set(3);
    cout<<"SET pos 3 to 1 in 10100 = "<<bt3<<endl;

    // .reset() FILL ALL POSITION BY 0
    bt1.reset();
    cout<<"RESET in 11111 = "<<bt1<<endl;

    bt3.reset(3);
    cout<<"RESET pos 3 to 0 in 11100 = "<<bt3<<endl;

    // test(index) check weather element at index is set or not
    cout<<"TEST pos 3 in 10100 = "<<bt3.test(3)<<endl;
    cout<<"TEST pos 2 in 10100 = "<<bt3.test(2)<<endl;

    return 0;
}