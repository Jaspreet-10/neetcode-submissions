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
    int findGoodNodes(TreeNode* root, int maxi, int &count){
        if(!root) return 0;
        if(root->val>=maxi) ++count;
        findGoodNodes(root->left, max(maxi, root->val), count);
        findGoodNodes(root->right, max(maxi, root->val), count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN, count = 0;
        findGoodNodes(root, maxi, count);
        return count;
    }
};
