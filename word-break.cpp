#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;

        for(string it : wordDict)   dict.insert(it);

        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j]){
                    if(dict.find(s.substr(j, i-j)) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};

int main(){
    
    
    return 0;
}