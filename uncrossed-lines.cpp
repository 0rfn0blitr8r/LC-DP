#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i  = m-1; i >= 0; i--){
            for(int j= n-1; j >= 0; j--){
                if(a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];
    }

    // Solution(){}
};

int main(){
    Solution *k = new Solution();
    
    vector<int> a = {10,5,2,1,5,2};
    vector<int> b = {2,5,1,2,5};

    cout<<k->maxUncrossedLines(a, b)<<nl;
    
    return 0;
}