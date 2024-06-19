#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int pp = 0, p = 1, c = 1;

        for(int i = 2; i <= n; i++){
            c = pp + p;
            pp = p; p = c;
        }

        return c;
    }
};

int main(){
    
    return 0;
}