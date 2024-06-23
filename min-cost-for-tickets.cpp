#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int mincostTickets(vector<int> &days, vector<int> &cost){
        int n = days.size();
        vector<int> dp(n+1, 1e9);

        for(int i = days.size()-1; i >= 0; i--){
            auto it = lower_bound(days.begin()+i, days.end(), days[i]+1) - days.begin();
            dp[i] = min(dp[i], cost[0] + dp[it]);
            
            auto it = lower_bound(days.begin()+i, days.end(), days[i]+7) - days.begin();
            dp[i] = min(dp[i], cost[1] + dp[it]);

            auto it = lower_bound(days.begin()+i, days.end(), days[i]+30) - days.begin();
            dp[i] = min(dp[i], cost[2] + dp[it]);
        }

        return dp[0];
    }
};

int main(){
    
    
    return 0;
}