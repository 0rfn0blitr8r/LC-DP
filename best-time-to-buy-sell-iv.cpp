#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp( n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int ndx = n-1; ndx >= 0; ndx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if(buy == 1){
                        dp[ndx][buy][cap] = max(
                            (-1)*prices[ndx] + dp[ndx+1][0][cap], 
                            0 + dp[ndx+1][1][cap]
                        );
                    }else{
                        dp[ndx][buy][cap] = max(
                            prices[ndx] + dp[ndx+1][1][cap-1],
                            0 + dp[ndx+1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};

int main(){
    
    
    return 0;
}