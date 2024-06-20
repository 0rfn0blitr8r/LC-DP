#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution{
public:
    int count(int d, vector<int> &pos){
        int cnt = 0, cur = pos[0];
        for(int i = 0; i < pos.size(); i++){
            if(pos[i] - cur >= d){
                cnt++;
                cur = pos[i];
            }
        }

        return cnt;
    }

    int maxDistance(vector<int>& pos, int m){
        sort(pos.begin(), pos.end());

        int l = pos[0], r = pos.back() - pos.front();

        while(l < r){
            int mid = r - (r-l)/2;

            if(count(mid, pos) >= m){
                r = mid-1;
            }else{
                l = mid;
            }
        }

        return l;
    }
};

int main(){
    
    
    return 0;
}