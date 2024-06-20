#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int fn(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(i < 0) return j+1; //insertions
        if(j < 0) return i+1; //deletions
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = fn(i-1, j-1, s, t, dp);

        return dp[i][j] = 1 + min({
            fn(i, j-1, s, t, dp),
            fn(i-1, j, s, t, dp),
            fn(i-1, j-1, s, t, dp)
        });
    }
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return fn(s.length()-1, t.length()-1, s, t, dp);
    }
};

int main(){
    
    
    return 0;
}