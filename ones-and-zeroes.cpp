#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int fn(vector<vector<vector<int>>> &dp, int ndx, int m, int n, vector<pair<int, int>> &pairs){
        if(ndx >= pairs.size())  return 0;
        if(pairs[ndx].first > m || pairs[ndx].second > n) return fn(dp, ndx+1, m, n, pairs);
        if(dp[ndx][m][n] != -1) return dp[ndx][m][n];

        //take
        int take = 1+fn(dp, ndx+1, m-pairs[ndx].first, n-pairs[ndx].second, pairs);
        //not take
        int nottake = fn(dp, ndx+1, m, n, pairs);

        return dp[ndx][m][n] = max(take, nottake);
    }

    int findMaxForm(vector<string>& arr, int m, int n) {
        vector<pair<int, int>> pairs;

        for(int i = 0 ; i < arr.size(); i++){
            int z = 0, o = 0;
            for(int j = 0; j < arr[i].length(); j++){
                if(arr[i][j] == '0'){
                    z++;
                }else{
                    o++;
                }
            }

            pairs.push_back(make_pair(z, o));
        }

        vector<vector<vector<int>>> dp(arr.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return fn(dp, 0, m, n, pairs);
    }
};

int main(){
    
    
    return 0;
}