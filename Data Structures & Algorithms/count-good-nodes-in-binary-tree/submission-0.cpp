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
     int helper(TreeNode* root, int&count, int maxi){
        if(!root) return count;
        if(root->val>=maxi) ++count;
        helper(root->left, count, max(maxi, root->val));
        helper(root->right, count, max(maxi, root->val));
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0, maxi = root->val;
        helper(root, count, maxi);
        return count;
    }
};
