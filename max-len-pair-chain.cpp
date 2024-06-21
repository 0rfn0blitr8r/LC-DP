#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        int res = 1;
        vector<int> dp(n, 1);

        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(pairs[i][1] < pairs[j][0]){
                    dp[i] = max(dp[i], 1+ dp[j]);

                    res = max(res, dp[i]);
                }
            }
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}