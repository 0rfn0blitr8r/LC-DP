#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0;
        int l = 0, m = 0;

        for(int r = 0; r < nums.size(); r++){
            if(nums[r]%2 == 1){
                odd++;
            }

            while(odd > k){
                if(nums[l]%2 == 1){
                    odd--;
                }

                l++;
                m = l;
            }

            if(odd == k){
                while(nums[m]%2 == 0){
                    m++;
                }

                res += (m-l) + 1;
            }
        }

        return res;
    }

    Solution(){}
};

int main(){
    Solution* obj = new Solution();
    vector<int> arr = {2,2,2,1,2,2,1,2,2,2};

    cout<<obj->numberOfSubarrays(arr, 2)<<nl;
    
    return 0;
}