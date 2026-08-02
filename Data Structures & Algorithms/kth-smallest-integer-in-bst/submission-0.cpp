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
     int preorder(TreeNode* root, int&k, int &ele){
        if(!root) return 0;
        preorder(root->left, k, ele);
        --k;
        if(k == 0){ ele = root->val; return ele; }
        preorder(root->right, k, ele);
        return ele;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ele = 0;
        preorder(root, k, ele);
        return ele;
    }
};
