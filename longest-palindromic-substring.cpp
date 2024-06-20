#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

class Solution {
public:
    void fn(string s, int i, int j, int& maxS, int& maxL){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }

        if(j-i-1 > maxL){
            maxS = i+1;
            maxL = j-i-1;
        }
    }
    
    string longestPalindrome(string s) {
        int maxS = 0, maxL = 1;

        for(int i = 0; i < s.length()-1; i++){
            fn(s, i, i, maxS, maxL);
            fn(s, i, i+1, maxS, maxL);
        }

        return s.substr(maxS, maxL);
    }
};

int main(){
    
    
    return 0;
}