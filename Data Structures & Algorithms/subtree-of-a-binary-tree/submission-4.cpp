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
    bool helper(TreeNode* p, TreeNode* q){
        if(!p and !q) return true;
        if((!p and q) or (p and !q)) return false;

        if(p->val == q->val){
            return helper(p->left, q->left) and helper(p->right, q->right);
        }
        else return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        if(!root) return false;
        if(root->val == subRoot->val){
           if(helper(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) or
        isSubtree(root->right, subRoot);
    }
};
