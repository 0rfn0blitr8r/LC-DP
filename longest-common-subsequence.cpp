#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        
        if(m == 0 || n == 0){
            return 0;
        }
        //                      s : i           t : j
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};

int main(){
    
    
    return 0;
}