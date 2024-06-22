#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<unsigned int> dp(target+1, 0);    
        dp[0] = 1;

        for(int tot = 1; tot <= target; tot++){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= tot){
                    dp[tot] += dp[tot - nums[i]];
                }else{
                    break;
                }
            }
        }

        return dp[target];
    }

    Solution(){}
};

int main(){
    Solution* o = new Solution();
    vector<int> arr = {1, 2, 3};
    int target = 4;
    cout<<o->combinationSum4(arr, target)<<nl;
    
    return 0;
}