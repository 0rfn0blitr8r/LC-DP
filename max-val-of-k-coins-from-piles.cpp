#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int dfs(int i, int coins, int n, vector<vector<int>>& dp, vector<vector<int>>& piles){
        if(i == n || coins == 0) return 0;
        if(dp[i][coins] != -1) return dp[i][coins];

        int res = dfs(i+1, coins, n, dp, piles);
        int curPiles = 0;

        int k = piles[i].size();
        for(int j = 0; j < min(coins, k); j++){
            curPiles += piles[i][j];
            res = max(res, curPiles + dfs(i+1, coins-j-1, n, dp, piles));
        }

        return dp[i][coins] = res;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return dfs(0, k, n, dp, piles);
    }
};

int main(){
    
    
    return 0;
}