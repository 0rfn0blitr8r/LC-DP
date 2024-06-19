#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int fn(int l, int i, vector<vector<int>> &g, vector<vector<int>> &dp){
        if(l == g.size()-1){
            return g[l][i];
        }if(dp[l][i] != -1){
            return dp[l][i];
        }

        return dp[l][i] = g[l][i] + min( fn(l+1, i, g, dp), fn(l+1, i+1, g, dp) );
    }

    int minimumTotal(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(0, 0, g, dp);
    }
};

int main(){
    
    
    return 0;
}