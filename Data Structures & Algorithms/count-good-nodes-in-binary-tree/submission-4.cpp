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
    int count = 0;
    int helper(TreeNode* root, int maxi){
        if(!root) return count;
        if(root->val>=maxi) ++count;
        helper(root->left, max(maxi, root->val));
        helper(root->right, max(maxi, root->val));
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        return helper(root, maxi);
    }
};
