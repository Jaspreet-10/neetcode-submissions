/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = -1;
    int helper(TreeNode* root, int &k){
        if(!root) return ans;
        helper(root->left, k);
        --k;
        if(k == 0){
            ans = root->val;
            return ans;
        }
        helper(root->right, k);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};
