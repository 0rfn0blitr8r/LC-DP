#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define pb push_back

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int res = 0;
            for(int j = 1; j <= i; j++){
                res += dp[j-1] * dp[i-j];
            }

            dp[i] = res;
        }

        return dp[n];
    }

    Solution1(){}
};

class Solution2{
public:
    vector<TreeNode*> genFn(int s, int e){
        vector<TreeNode*> res;

        if(s > e){
            res.push_back(NULL);
            return res;
        }

        for(int i = s; i <= e; i++){
            vector<TreeNode*> leftSubVect = genFn(s, i-1);
            vector<TreeNode*> rightSubVect = genFn(i+1, e);

            for(TreeNode* leftTree : leftSubVect){
                for(TreeNode* rightTree : rightSubVect){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = leftTree;
                    cur->right = rightTree;

                    res.push_back(cur);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return n ? genFn(1, n) : vector<TreeNode*>();
    }
};


int main(){
    Solution1* o = new Solution1();

    cout<<o->numTrees(5)<<nl;
    
    return 0;
}