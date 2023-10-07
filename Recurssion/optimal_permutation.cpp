/*
For n variable we have n! permutations so, 
if we need to find kth permutation in an order then:

1st Way is Bruth Force Technique or Reccursion technique
All permutation is stored in a data structure and it is sorted and the index 
to get specific solution 
TC = n!(to get all permutation) + n (adding to the data structure) + nlog (for sorting)
It a lot of time.

2nd Way is 
to generate n variable permutation it take n! time.
eg: variable are [1, 2, 3, 4] => 4! => 24
so, 
1 + permutataion([2, 3, 4]) = 3! = 6
2 + permutataion([1, 3, 4]) = 3! = 6
3 + permutataion([1, 2, 4]) = 3! = 6
4 + permutataion([1, 2, 3]) = 3! = 6
                           total = 24
so, to get kth we just need to find where it will lie

CODING LOGIC = 
   index =  0  1  2  3
variable = [1, 2, 3, 4]
for k value we pass k = k-1
k=17 we pass k=17-1 => k=16

permutation are : 
1, 2, 3, 4 --> 0th permutation
1, 2, 4, 3 --> 1st permutation
..............................
4, 3, 2, 1 --> 23th permutation

STEP 1: 
so, 
1 + per([2, 3, 4]) = 3! = 6 = contain 0th to 5th permutations
2 + per([1, 3, 4]) = 3! = 6 = contain 6th to 11th permutations
3 + per([1, 2, 4]) = 3! = 6 = contain 12th to 17th permutations
4 + per([1, 2, 3]) = 3! = 6 = contain 18th to 23th permutations

if k=16 the we look at 16th permutation for 0th base indexing

so to get the index of value of specific that range
were our permutation lie will be :
index = k / (n-1)!

index = 16 / (4-1)! => 16 / 3! => 16 / 6 => 2
variable[index] => variable[2] = 3


ans = 3, _, _, _
now remove variable at index=3
            0  1  2
variable = [1, 2, 4]

so,  16th permutation belong to 3 + per([1, 2, 4]) i.e 12th to 17th permutation range

STEP 2:
k % (n-1)! will give the indexes from that between range 

k % (4-1)! => 16 % 3! => 16 % 6 => 4
so, 4th index form range 12th to 17th is required permutation i.e is:
  :. 12th + 4 => 16th one

  3 + per([1, 2, 4]) :
  [3, 1, 2, 4] --> 12th [index 0]
  [3, 1, 4, 2] --> 13th [index 1]
  [3, 2, 1, 4] --> 14th [index 2]
  [3, 2, 4, 1] --> 15th [index 3]
  [3, 4, 1, 2] --> 16th [index 4] -- required permutation
  [3, 4, 2, 1] --> 17th [index 5]


STEP 3:
Now reperate the same procedure to get new kth permutation from (n-1) variable

3 _ _ _ is required one from the four place, now to get next variable
we repeate the prcedure:
So, to get next place value we:
Now find 4th index permutation form [1, 2, 4] variable

Similarly we repeate the steps 
-----------------------------------------------------------------------------------------
old k=17, old n=4
k=4, n=3
index = k / (n-1)! => 4 / 2! => 2
variable[index] => variable[2] => 4

ans = 3, 4, _, _
remove variable at index=2
            0  1
variable = [1, 2]

3, 1 + per([2, 4]) = 2! = 2 = contain 12th to 13th permutations 
3, 2 + per([1, 4]) = 2! = 2 = contain 14th to 15th permutations 
3, 4 + per([2, 3]) = 2! = 2 = contain 16th to 17th permutations

4 % (3-1)! => 4 % 2! => 4 % 2 => 0
so, 2nd index form range 12th to 13th is required permutation i.e is:
  :. 12th + 2 => 16th one
  -------------------------------------------

  Time Comp = Big O(n^2)
  n for adding string and n for removing a particular character

*/


#include<bits/stdc++.h>
using namespace std;


int fact(int n) {
    if(n <= 1)
        return 1;
    return n * fact(n-1);
}


void findPermutation(string variable, int n, int k, string &ans) {
    if(n == 1) {
        ans.push_back(variable[0]);
        return;
    }

    int n_fact = fact(n-1);
    int index = floor(k / n_fact);

    ans.push_back(variable[index]);
    variable.erase(variable.begin() + index);

    k = k % n_fact;
    findPermutation(variable, n-1, k, ans);
}


int main()
{
    string variable = "12345";
    string ans;
    int n = variable.length();
    int k = 55;
    
    findPermutation(variable, n, k-1, ans);
    cout<<ans;
    return 0;
}