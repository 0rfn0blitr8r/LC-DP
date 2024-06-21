#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                if(s[i] == s[n-1-j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return n - dp[n][n];
    }
};

int main(){
    
    return 0;
}