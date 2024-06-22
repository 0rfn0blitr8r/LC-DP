#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
    int mod = 1e9 + 7;
public:
    int fn(int len, int low, int high, int zero, int one, vector<int> &dp){
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];

        int res = 0;
        if(len >= low) res = 1;

        res += fn(len + zero, low, high, zero, one, dp);
        res += fn(len + one , low, high, zero, one, dp);

        return dp[len] = res % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);

        return fn(0, low, high, zero, one, dp);
    }
};

int main(){
    
    
    return 0;
}