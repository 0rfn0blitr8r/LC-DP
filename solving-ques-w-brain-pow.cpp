#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int fn(int ndx, vector<vector<int>> &ques, vector<long long> &dp){
        if(ndx >= ques.size()){
            return 0;
        }if(dp[ndx] != -1){
            return dp[ndx];
        }
        
        //understamding that there will be a jump is v imp
        return dp[ndx] = max(
                        fn(ndx+1, ques, dp), 
                        ques[ndx][0] + fn(ndx + 1 + ques[ndx][1], ques, dp)
                        );
    }

    long long mostPoints(vector<vector<int>>& ques) {
        vector<long long> dp(ques.size(), -1); 
        return fn(0, ques, dp);
    }
};

int main(){
    
    
    return 0;
}

/*
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][0];
        long long ans = dp[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int k = i + questions[i][1] + 1;
            if (k < n)
            {
                dp[i] = (dp[k] + questions[i][0]) > dp[i + 1] ? (dp[k] + questions[i][0]) : dp[i + 1];
            }
            else
            {
                dp[i] = questions[i][0] > dp[i + 1] ? questions[i][0] : dp[i + 1];
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};
*/