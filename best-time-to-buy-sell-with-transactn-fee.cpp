#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    map<pair<int, bool>, int> dp;

    int dfs(int ndx, bool buying, vector<int> &prices, int fee){
        if(ndx == prices.size()){
            return 0;
        }if(dp.find({ndx, buying}) != dp.end()){
            return dp[{ndx, buying}];
        }

        int fut = dfs(ndx+1, buying, prices, fee);

        if(buying){
            int buy = dfs(ndx+1, !buying, prices, fee) - prices[ndx];
            dp[{ndx, buying}] = max(buy, fut);
        }else{
            int sell = dfs(ndx+1, !buying, prices, fee) + prices[ndx] - fee;
            dp[{ndx, buying}] = max(sell, fut);
        }

        return dp[{ndx, buying}];
    }
  
    int maxProfit(vector<int>& prices, int fee) {
        return dfs(0, true, prices, fee);    
    }

    Solution(){}
};

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    Solution* o = new Solution();

    cout<<o->maxProfit(prices, fee)<<nl;
    
    return 0;
}