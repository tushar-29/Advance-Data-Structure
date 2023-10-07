/*
Ninja Training 
Here we need to select the activity according to given days. Each day's activity 
contain some points. 
Find the maximum points that can be achieved form the activiy done such that 
the selected activity cannot be performed in the next day.

*/

#include<bits/stdc++.h>
using namespace std;


int findMax(vector<int> sch, int prevAct) {
    int temp=0, ind=-1;
    for(int i=0; i<sch.size(); i++) {
        if(prevAct != i && temp < sch[i]) {
            ind = i;
            temp = sch[i];
        }
    }
    return ind;
}


int ninjaTraining_recc(vector<vector<int>> schedule, int day, int prevAct=-1) {
    if(day == 0) {
        return schedule[day][findMax(schedule[day], prevAct)];
    }

    int value=0, temp=0, index=0, index2=0, i=0;
    for(i=0; i<schedule[day].size(); i++) {
        if(prevAct != i) {
            value = schedule[day][i] + ninjaTraining_recc(schedule, day-1, i);
            temp = max(temp, value);
        }
    }

    return temp;
}

int ninjaTraining_memo(vector<vector<int>> schedule, int day, int prevAct,
vector<vector<int>> &dp) {
    
    if(dp[day][prevAct] != -1) 
        return dp[day][prevAct];

    if(day == 0) {
        return schedule[day][findMax(schedule[day], prevAct)];
    }

    int value=0, temp=0, index=0, index2=0, i=0;
    for(i=0; i<schedule[day].size(); i++) {
        if(prevAct != i) {
            value = schedule[day][i] + ninjaTraining_memo(schedule, day-1, i, dp);
            temp = max(temp, value);
        }
    }

    return dp[day][prevAct] = temp;
}


int ninjaTraining_tabu(vector<vector<int>> schedule) {
    int value=0, size=schedule[0].size();
    int i=0, prevAct=0, task=0;

    vector<vector<int>> dp (schedule.size(), vector<int> (schedule[size].size()+1, 0));

    // initiall condition
    dp[0][0] = max(schedule[0][1], schedule[0][2]);
    dp[0][1] = max(schedule[0][0], schedule[0][2]);
    dp[0][2] = max(schedule[0][0], schedule[0][1]);
    dp[0][3] = max(max(schedule[0][0], schedule[0][1]), schedule[0][2]);

    
    for(i=1; i<schedule.size(); i++) {
        for(prevAct=0; prevAct<size+1; prevAct++) {
            dp[i][prevAct] = 0;

            for(task=0; task<size; task++) {
                if(prevAct != task) {
                    value = schedule[i][task] + dp[i-1][task];
                    dp[i][prevAct] = max(dp[i][prevAct], value);
                }
            }
        }   
    }
    return dp[i-1][prevAct-1];
}


int ninjaTraining_tabu2(vector<vector<int>> schedule) {
    int value=0, size=schedule[0].size();
    int i=0, prevAct=0, task=0;

    vector<int> dp (schedule.size()+1, 0);

    // initiall condition
    dp[0] = max(schedule[0][1], schedule[0][2]);
    dp[1] = max(schedule[0][0], schedule[0][2]);
    dp[2] = max(schedule[0][0], schedule[0][1]);
    dp[3] = max(max(schedule[0][0], schedule[0][1]), schedule[0][2]);

    
    for(i=1; i<schedule.size(); i++) {
        vector<int> temp(4, 0);

        for(prevAct=0; prevAct<size+1; prevAct++) {
            temp[prevAct] = 0;

            for(task=0; task<size; task++) {
                if(prevAct != task) {
                    value = schedule[i][task] + dp[task];
                    temp[prevAct] = max(temp[prevAct], value);
                }
            }
        }  
        dp = temp; 
    }
    return dp[prevAct-1];
}


void Main(vector<vector<int>> schedule, int day) {
    if(day == 0)
        return;
    
    cout<<ninjaTraining_recc(schedule, day-1)<<endl;

    vector<vector<int>> dp(day, vector<int> (day+1, -1));
    cout<<ninjaTraining_memo(schedule, day-1, 3, dp)<<endl;

    cout<<ninjaTraining_tabu(schedule)<<endl;
    cout<<ninjaTraining_tabu2(schedule)<<endl;
}


int main()
{
    vector<vector<int>> schedule = {
        {10, 30, 40}, 
        {20, 50, 10},
        {30, 40, 20},
        {50, 20, 40},
        {10, 30, 50}
    };

    int day = schedule.size();

    Main(schedule, day);

    return 0;
}
