#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define ll long long
#define pb push_back

// WILL GIVE TLE
// DP not applied 
class Solution0 {
public:
    unordered_map<char, vector<char>> mp;

    int fn(int ndx, int n, string& temp) {
        if (ndx == n)
            return 1;
        int res = 0;
        char prevChar = temp[ndx - 1];
        for (char c : mp[prevChar]) {
            temp += c;
            res += fn(ndx + 1, n, temp);
            temp.pop_back();
        }
        return res;
    }

    int countVowelPermutation(int n) {
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['o'] = {'i', 'u'};
        mp['u'] = {'a'};

        int res = 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string temp = "";

        for (auto it : mp) {
            temp += it.first;
            res += fn(1, n, temp);
            temp.pop_back();
        }

        return res;
    }
};

// Bottom-Up dp solution
class Solution {
public:
    const unsigned int mod = 1e9 + 7;

    /*
    0 | a | e
    1 | e | a, i
    2 | i | a, e, o, u
    3 | o | i, u
    4 | u | a
    */

    int countVowelPermutation(int n) {
        vector<int> cur(5, 0), prev(5, 1);
        for(int i = 1; i < n; i++){
            cur[0] = (prev[1]) % mod;
            cur[1] = (prev[0] + prev[2]) % mod;
            cur[2] = ((prev[0])% mod + (prev[1])% mod + (prev[3])% mod + (prev[4])% mod) % mod;
            cur[3] = (prev[2] + prev[4]) % mod;
            cur[4] = (prev[0]) % mod;

            prev = cur;
        }

        int res = 0;
        for(auto it : prev) res = (res + it)% mod;

        return res;
    }
};

int main(){
    
    
    return 0;
}