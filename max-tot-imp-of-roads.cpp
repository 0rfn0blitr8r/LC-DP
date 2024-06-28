#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define ll long long
#define pb push_back

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        vector<int> edgeCnt(n, 0);

        for(auto it : roads){
            edgeCnt[it[0]]++;
            edgeCnt[it[1]]++;
        }

        sort(edgeCnt.begin(), edgeCnt.end());

        long long label = 1;

        for(auto it : edgeCnt){
            res += it*(label++);
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}