#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    vector<vector<int>> dp;

    int dead_end_sum(string str, int ndx){
        int res = 0;
        for(; ndx < str.length(); ndx++){
            res += int(str[ndx]);
        }

        return res;
    }

    int sub(int i, int j, int m, int n, string s, string t){
        if(i == m || j == n){
            if(i == m && j == n) return 0;

            return (i == m) ? dead_end_sum(t, j) : dead_end_sum(s, i);
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = sub(i+1, j+1, m, n, s ,t);

        return dp[i][j] = min(  sub(i+1, j, m, n, s, t) + int(s[i]),
                                sub(i, j+1, m, n, s, t) + int(t[j]) );
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        dp = vector<vector<int>>(m+1 , vector<int>(n+1, -1));

        return sub(0, 0, m, n, s1, s2);
    }
};

int main(){
    
    
    return 0;
}