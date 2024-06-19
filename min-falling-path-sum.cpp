#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int fn(int r, int c, int n, vector<vector<int>> &g, vector<vector<int>> &dp){
        if(r == n){
            return 0;
        }if(dp[r][c] != -100000){
            return dp[r][c];
        }

        int ans = fn(r+1, c, n, g, dp);

        if(c-1 >= 0){
            ans = min(ans, fn(r+1, c-1, n, g, dp));
        }if(c+1 < n){
            ans = min(ans, fn(r+1, c+1, n, g, dp));
        }

        ans += g[r][c];

        return dp[r][c] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> dp(n, vector<int>(n, -100000));

        int res = 1e9;

        for(int j = 0; j < n; j++){
            res = min(res, fn(0, j, n, g, dp));
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}