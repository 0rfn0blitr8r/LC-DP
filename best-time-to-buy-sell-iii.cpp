#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ndx = n-1; ndx >= 0; ndx--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap < 3; cap++){
                    //buy is possible
                    if(buy == 1){
                        dp[ndx][buy][cap] = max(-1*prices[ndx] + dp[ndx+1][0][cap], //you buy
                                                0 + dp[ndx+1][1][cap]);             //you don't buy
                    }else{
                        dp[ndx][buy][cap] = max(prices[ndx] + dp[ndx+1][1][cap-1],  //you sell
                                                0 + dp[ndx+1][0][cap]);             //you don't sell
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

int main(){
    
    
    return 0;
}