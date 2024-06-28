#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define ll long long
#define pb push_back

class Solution2 {
public:
    int costFn(int ndx, vector<vector<int>>& costs, int col, vector<vector<int>>& dp, int k){
        if(ndx == costs.size()) return 0;
        if(dp[ndx][col] != -1) return dp[ndx][col];

        int mini = INT_MAX;
        for(int i = 0; i < k; i++){
            if(i != col){
                mini = min(mini, costFn(ndx+1, costs, i, dp ,k));
            }
        }

        return dp[ndx][col] = costs[ndx][col] + mini;
    }


    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>>dp(n, vector<int>(k, -1));

        int res = INT_MAX;
        for(int i = 0; i < k; i++){
            res = min(res, costFn(0, costs, i, dp, k));
        }

        return res;
    }

    Solution2(){}
};

int main(){
    Solution2* o = new Solution2();

    // vector<vector<int>> v = {{17,2,17},{16,16,5},{14,3,19}};
    vector<vector<int>> v = {{7, 6, 2}};
    cout<<o->minCostII(v)<<nl;
    return 0;
}