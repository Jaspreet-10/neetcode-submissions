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
    bool checkIfSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((p && !q) || (q && !p)) return false;
        if(p->val == q->val){
            return checkIfSameTree(p->left, q->left) &&
                    checkIfSameTree(p->right, q->right);
        }else return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val) 
            if(checkIfSameTree(root, subRoot)) 
                return true;
        if(isSubtree(root->left, subRoot)) return true;
        if(isSubtree(root->right, subRoot)) return true;
        return false;
    }
};
