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
    int findDiameter(TreeNode*root, int &maxi){
        if(!root) return 0;
        int ld = findDiameter(root->left, maxi);
        int rd = findDiameter(root->right, maxi);
        maxi = max(maxi, ld+rd);
        return 1+max(ld, rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi = 0;
        findDiameter(root, maxi);
        return maxi;
    }
};
