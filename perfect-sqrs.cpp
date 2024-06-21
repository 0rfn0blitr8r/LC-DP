#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int numSquares(int n){
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int target = 1; target <= n; target++){
            for(int j = 1; j <= target; j++){
                if(target - j*j < 0)    break;

                dp[target] = min(dp[target], 1 + dp[target- (j*j)]);
            }
        }

        return dp[n];
    }

    Solution(){}
};

int main(){
    Solution* obj = new Solution();

    while(true){
        int k;
        cin>>k;
        cout<<obj->numSquares(k)<<nl<<"____"<<nl;
    }
    
    return 0;
}