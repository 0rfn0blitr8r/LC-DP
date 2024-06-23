#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int numDecodings(string s){
        if(s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1, 0); dp[0] = 1; dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int ones = stoi(s.substr(i-1, 1)), tens = stoi(s.substr(i-2, 2));

            if(ones <= 9 && ones>= 1) dp[i] += dp[i-1];
            if(tens <= 26 && tens>= 10) dp[i] += dp[i-2];
        }

        return dp[n];
    }

    Solution(){};
};

int main(){
    Solution* o = new Solution();

    cout<<o->numDecodings("123")<<nl;
    
    return 0;
}