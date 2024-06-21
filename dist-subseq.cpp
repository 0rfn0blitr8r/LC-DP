#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    unordered_map<pair<int, int>, int> dp;

    int dfs(int i, int j, string &s, string &t){
        if(j == t.length())   return 1;
        if(i == s.length())   return 0;

        if(dp.find(make_pair(i, j)) != dp.end()) return dp[make_pair(i, j)];

        dp[make_pair(i, j)] = dfs(i+1, j, s, t);

        if(s[i] == t[j]) dp[make_pair(i, j)] += dfs(i+1, j+1, s, t);

        return dp[make_pair(i, j)];
    }
  
    int numDistinct(string s, string t) {
        return dfs(0, 0, s, t);
    }
};

int main(){
    
    
    return 0;
}