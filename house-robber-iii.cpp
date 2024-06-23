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

class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL) return make_pair(0, 0);

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        pair<int, int> res;

        //with root
        res.first = root->val + left.second + right.second;

        //without root
        res.second = max(left.first, left.second) + max(right.first, right.second);

        //[with root, withour root]
        return res;
    }

    int rob(TreeNode* root) {
        if(root == NULL) return 0;

        pair<int, int> res = dfs(root);

        return max(res.first, res.second);
    }
};

int main(){
    
    
    return 0;
}