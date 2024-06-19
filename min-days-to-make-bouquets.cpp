#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    bool isPossible(vector<int> &arr, int day, int m, int k){
        int n = arr.size(), cnt = 0, noOfB = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] <= day){
                cnt++;
            }else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }

        noOfB += (cnt / k);

        return noOfB >= m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val > n){
            return -1;
        }

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i : bloomDay){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        int low = mini, hi = maxi;

        while(low <= hi){
            int mid = (low + hi)/2;

            if(isPossible(bloomDay, mid, m, k)){
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};

int main(){
    
    
    return 0;
}