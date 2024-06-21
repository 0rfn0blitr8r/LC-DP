#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution1 {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1, amt+1); dp[0] = 0;

        for(int i = 1; i < amt+1; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i-coins[j] >= 0) dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }

        return (dp[amt] == amt+1) ? -1 : dp[amt];
    }
};

class Solution2{
public:
    map<pair<int, int>, int> dp;

    int dfs(int i, int sum, int amt, vector<int> &coins){
        if(sum == amt) return 1;
        if(sum > amt) return 0;
        if(i == coins.size()) return 0;
        if(dp.find({i, sum}) != dp.end()) return dp[{i, sum}];

        return dp[{i, sum}] =   dfs(i+1, sum, amt, coins) + 
                                dfs(i, sum + coins[i], amt, coins);
    } 

    int change(int amt, vector<int> coins){
        return dfs(0, 0, amt, coins);
    }
};

int main(){
    
    
    return 0;
}