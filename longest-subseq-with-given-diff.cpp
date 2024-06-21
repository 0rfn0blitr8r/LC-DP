#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int, int> dp;
        int maxLen = 1;

        for(int i : arr){
            dp[i] = dp[i-d] + 1;
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    Solution(){}
};

int main(){
    Solution *k = new Solution();
    vector<int> v = {1, 3, 5, 7};
    
    cout<<k->longestSubsequence(v, 2)<<nl;
    
    return 0;
}