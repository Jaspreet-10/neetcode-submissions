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
    bool checkBST(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val>mini and root->val<maxi){
        return checkBST(root->left, mini, root->val) and
        checkBST(root->right, root->val, maxi);
        }else return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long mini = LLONG_MIN, maxi = LLONG_MAX;
        return checkBST(root, mini, maxi);
    }
};
