#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int fn(int n, vector<int> &dp){
        if(dp[n] != -1){
            return dp[n];
        }if(n <= 1){
            return 1;
        }if(n == 2){
            return 2;
        }

        return dp[n] = fn(n-2, dp) + fn(n-1, dp);
    }

    int climb(int n){
        vector<int> dp(n+1, -1);

        return fn(n, dp);
    }
};

int main(){
    
    
    return 0;
}