#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int fn(int ndx, int prev, int n, vector<int>& a, vector<vector<int>> &dp){
        if(ndx == n)    return 0;
        if(dp[ndx][prev+1] != -1)   return dp[ndx][prev+1];

        int len = 0 + fn(ndx+1, prev, n, a, dp);

        if(prev == -1 || a[ndx] > a[prev]){
            len = max(len, 1 + fn(ndx+1, ndx, n, a, dp));
        }

        return dp[ndx][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return fn(0, -1, n, nums, dp);
    }
};

int main(){
    
    
    return 0;
}

/*
class Solution {
public:

    
        //Basic recursion based method.
    
    int LIS(vector<int>& nums, int currIndex, int prevIndex)
    {
        if(nums.size() == currIndex)
            return 0;

        int pickElement = 0;
        if(prevIndex == -1 || nums.at(currIndex) > nums.at(prevIndex))
            pickElement = 1 + LIS(nums, currIndex + 1, currIndex);

        int doNotPickElement = 0;
        doNotPickElement = LIS(nums, currIndex + 1, prevIndex);

        return max(pickElement, doNotPickElement);
    }

    
        //This is recursion plus memoization
    
    int LISMemoization(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp)
    {
        if(nums.size() == currIndex)
            return 0;

        // Handle the index of prev <- Because it is starting from -1. So for coding do +1.
        if(dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];

        int pickElement = 0;
        if(prevIndex == -1 || nums.at(currIndex) > nums.at(prevIndex))
            pickElement = 1 + LIS(nums, currIndex + 1, currIndex);

        int doNotPickElement = 0;
        doNotPickElement = LIS(nums, currIndex + 1, prevIndex);
        return dp[currIndex][prevIndex + 1] = max(pickElement, doNotPickElement);
    }

    
    //    Bottom up dp. T.C. O(n^2).
    //                 S.C. O(n^2)
    
    int LISTabular(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        
            //We are following bottom up approach.
        
            //Do not forget to do +1 for prev Index. As it is going from -1 to n-1.
        
        for(int currIndex = n-1; currIndex >= 0; --currIndex)
        {
            for(int prevIndex = currIndex-1; prevIndex >= -1; --prevIndex)
            {
                int pickElement = 0;
                if(prevIndex == -1 || nums.at(currIndex) > nums.at(prevIndex))
                    pickElement = 1 + dp[currIndex + 1][currIndex + 1]; // This is because //prev will go from -1 to n-1. So for index -1 + 1 

                int doNotPickElement = 0;
                doNotPickElement = dp[currIndex + 1][prevIndex + 1];

                dp[currIndex][prevIndex + 1] = max(pickElement, doNotPickElement);
            }
        }

        return dp[0][0];
    }

     
        //Bottom up dp. T.C. O(n^2).
        //               S.C. O(n)  <- Space optimized
//
        //If you observe -> dp[currIndex] = max(dp[currIndex +1][prev + 1], dp[currIndex +1][currIndex])
//
        //It means, currIndex depends only on next index (currIndex + 1).
        //So, we can have only 2 dp. currRow and nextRow
    
    int LISSpaceOptimized(vector<int>& nums)
    {
        int n = nums.size();
        //vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
            //We are following bottom up approach.
       
            //Do not forget to do +1 for prev Index. As it is going from -1 to n-1.
        
        for(int currIndex = n-1; currIndex >= 0; --currIndex)
        {
            for(int prevIndex = currIndex-1; prevIndex >= -1; --prevIndex)
            {
                int pickElement = 0;
                if(prevIndex == -1 || nums.at(currIndex) > nums.at(prevIndex))
                    pickElement = 1 + nextRow[currIndex + 1]; // This is because //prev will go from -1 to n-1. So for index -1 + 1 

                int doNotPickElement = 0;
                doNotPickElement = nextRow[prevIndex + 1];

                currRow[prevIndex + 1] = max(pickElement, doNotPickElement);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

        //Most optimized way. DP + BinarySearch
        //T.C. -> O(nlogn)
        //S.C. -> O(n)

    int LISDpPlusBinarySearch(vector<int>& nums)
    {
  
//            Logic: We just need the length of answer vector/array.
//                    We do not need the exact answer. So, we will increase
//                    Ans vector if curr element is > last element.
//                    Or else we will find the correct position of that element and will put into the ans vector.
//
//                    This ans vector does not contain actual ans. But it is sure that length of this ans vector will be correct.
//
//                    We know that answer vector will be in sorted order only. So we will use lower bound to find the correct position
//                    of curr element.
  
        vector<int> ans;
        ans.push_back(nums.at(0));

        for(int currIndex = 1; currIndex < nums.size(); ++currIndex)
        {
            int element = nums.at(currIndex);
            if(element > ans.back())
                ans.push_back(element);
            else{
                int pos = lower_bound(ans.begin(), ans.end(), element) - ans.begin();
                ans[pos] = element;
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int currIndex = 0;
        int prevIndex = -1;

        //return LIS(nums, currIndex, prevIndex);

        int n = nums.size();
        //vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // currIndex -> 0 .... n-1 and prevIndex = -1 to n-1 <- total n + 1 length
        //return LISMemoization(nums, currIndex, prevIndex, dp);

        //int res = LISTabular(nums);
        //int res = LISSpaceOptimized(nums);

        int res = LISDpPlusBinarySearch(nums);
        return res;
    }
};
*/