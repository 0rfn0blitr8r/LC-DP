#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    map<pair<int, bool>, int> dp;

    int dfs(int ndx, bool buying, vector<int> &prices){
        if(ndx >= prices.size()){
            return 0;
        }if(dp.find({ndx, buying}) !=  dp.end()){
            return dp[{ndx, buying}];
        }

        int cooldown = dfs(ndx+1, buying, prices);

        if(buying){
            int buy = dfs(ndx+1, !buying, prices) - prices[ndx];
            dp[{ndx, buying}] = max(buy, cooldown);
        }else{
            int sell = prices[ndx] + dfs(ndx+2, !buying, prices);
            dp[{ndx, buying}] = max(sell, cooldown);
        }

        return dp[{ndx, buying}];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        return dfs(0, true, prices);
    }

    Solution(){}
};

int main(){
    vector<int> arr = {1,2,3,0,2};
    Solution* obj = new Solution();

    cout<<obj->maxProfit(arr)<<nl;
    
    return 0;
}