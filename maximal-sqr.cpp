#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int maximalSquare(vector<vector<char>> &g){
        int m = g.size(), n = g[0].size();

        int maxi = 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(g[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i+1][j], dp[i+1][j+1], dp[i][j+1]});
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        return maxi;
    }

    Solution(){}
};

int main(){
    vector<vector<char>> g = {
                    {'1','0','1','0','0'},
                    {'1','0','1','1','1'},
                    {'1','1','1','1','1'},
                    {'1','0','0','1','0'}
                            };

    Solution* obj = new Solution();

    int res = obj->maximalSquare(g);
    cout<<res<<nl;
    
    return 0;
}