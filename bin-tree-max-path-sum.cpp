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
    int maxi;

    int sumFn(TreeNode* root){
        if(!root) return 0;

        int left = max(0, sumFn(root->left));
        int right = max(0, sumFn(root->right));

        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        sumFn(root);
         
        return maxi;
    }
};

int main(){
    
    
    return 0;
}