#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int longestSubarray(vector<int>& nums, int lim) {
        deque<int> minDeq, maxDeq;
        int res = 1;

        int l = 0;

        for(int r = 0; r < nums.size(); r++){
            while(!maxDeq.empty() && maxDeq.back() < nums[r]){
                maxDeq.pop_back();
            }
            maxDeq.push_back(nums[r]);
            
            while(!minDeq.empty() && minDeq.back() > nums[r]){
                minDeq.pop_back();
            }
            minDeq.push_back(nums[r]);

            while(maxDeq.front() - minDeq.front() > lim){
                if(maxDeq.front() == nums[l]) maxDeq.pop_front();
                if(minDeq.front() == nums[l]) minDeq.pop_front();
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }

    Solution(){}
};

int main(){
    Solution* o = new Solution();
    vector<int> v = {8, 2, 4, 7};
    int lim = 4;
    cout<<o->longestSubarray(v, lim)<<nl;
    
    return 0;
}