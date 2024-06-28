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



int main(){
    
    
    return 0;
}