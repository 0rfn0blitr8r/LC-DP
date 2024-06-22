#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, m = 0;
        int res = 0;

        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[m]]--;
                if(mp[nums[m]] == 0){
                    mp.erase(nums[m]);
                }

                m++; l = m;
            }

            while(mp[nums[m]] > 1){
                mp[nums[m]]--;
                m++;
            }

            if(mp.size() == k){
                res += m-l+1;
            }
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}