#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> v(nums.size(), INT_MAX), ans;

        for(int i : nums){
            auto ub = upper_bound(v.begin(), v.end(), i);
            ans.emplace_back(ub - v.begin() + 1);
            *ub = i;
        }

        return ans;
    }
};

int main(){

    
    return 0;
}