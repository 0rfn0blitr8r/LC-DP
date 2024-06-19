#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int deleteAndEarn(vector<int> &nums){
        int maxi = 0;
        vector<int> fmap(10001, 0);
        for(int i : nums){
            fmap[i] += i;
            maxi = max(maxi, i);
        }

        vector<int> dp(maxi+1);
        dp[0] = fmap[0]; dp[1] = max(fmap[0], fmap[1]);

        for(int i = 2; i <= maxi; i++){
            dp[i] = max(dp[i-1], dp[i-2]+fmap[i]);
        }

        return dp[maxi];
    }
};

int main(){
    
    
    return 0;
}