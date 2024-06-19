#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int a = cost[n-1], b = 0;

        for(int i = n-2; i >= 0; i--){
            cost[i] += min(a, b);
            a = cost[i], b = cost[i+1];
        }

        return min(cost[0], cost[1]);
    }
};

int main(){
    
    
    return 0;
}