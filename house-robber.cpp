#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return (nums[0] > 0) ? nums[0] : 0;
        }if(n == 2){
            return (min(nums[0], nums[1]) > 0) ? min(nums[0], nums[1]) : 0;
        }

        vector<long long> dp(n, 0);
        dp[0] = nums[0], dp[1] = min(nums[0], nums[1]);

        long long res = INT_MIN;

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}