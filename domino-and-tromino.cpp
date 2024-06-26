#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int mod = 1e9+7;

    int numTilings(long long n) {
        vector<long long> v(10001, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;

        if(n <= 3){
            return v[n];
        }for(int i = 4; i <= n; i++){
            v[i] = 2*v[i-1] + v[i-3];
            v[i] %= mod;
        }

        return v[n];
    }
};

int main(){
    
    
    return 0;
}