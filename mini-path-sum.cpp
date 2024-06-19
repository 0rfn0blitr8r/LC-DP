#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[m-1][n-1] = grid[m-1][n-1];
                    continue;
                }

                int mini = INT_MAX;

                if(i+1 < m){
                    mini = min(mini, dp[i+1][j]);
                }if(j+1< n){
                    mini = min(mini, dp[i][j+1]);
                }

                dp[i][j] = grid[i][j] + mini;
            }
        }

        return dp[0][0];
    }
};

int main(){
    
    
    return 0;
}