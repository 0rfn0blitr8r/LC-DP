#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int min) {
        int l = 0, window = 0, maxWindow = INT_MIN, satis = 0;

        for(int r = 0 ; r < grumpy.size(); r++){
            if(grumpy[r] == 1){
                window += customers[r];
            }else{
                satis += customers[r];
            }if(r-l+1 > min){
                if(grumpy[l] == 1){
                    window -= customers[l];
                }l++;
            }

            maxWindow = max(window, maxWindow);
        }

        return maxWindow + satis;
    }
};

int main(){
    
    
    return 0;
}