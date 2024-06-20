#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> dp;
        int lenLIS = 0, res = 0;

        for(int i = nums.size()-1; i >= 0; i--){
            int maxLen = 1, maxCnt = 1;

            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    int len = dp[j].first;
                    int cnt = dp[j].second;

                    if(len+1 > maxLen){
                        maxLen = len+1;
                        maxCnt = cnt;
                    }else if(len+1 == maxLen){
                        maxCnt += cnt;
                    }
                }
            }

            if(maxLen > lenLIS){
                lenLIS = maxLen;
                res = maxCnt;
            }else if(maxLen == lenLIS){
                res += maxCnt;
            }

            dp[i] = make_pair(maxLen, maxCnt);
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}