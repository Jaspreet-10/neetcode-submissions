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
    int findDepth(TreeNode* root){
        if(!root) return 0;
        int lh = findDepth(root->left);
        int rh = findDepth(root->right);
        return 1+max(lh, rh);
    }
    int maxDepth(TreeNode* root) {
        return findDepth(root);
    }
};
