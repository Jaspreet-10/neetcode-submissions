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
    TreeNode* constructBinaryTree(vector<int>& preorder, vector<int>& inorder,
                                  unordered_map<int, int>& m, int prestart, int preend, int instart,
                                  int inend) {
        if (inend < instart || prestart > preend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inRoot = m[preorder[prestart]];
        int numsLeft = inRoot - instart;
        root->left = constructBinaryTree(preorder, inorder, m, prestart + 1, prestart + numsLeft,
                                         instart, inRoot - 1);
        root->right = constructBinaryTree(preorder, inorder, m, prestart + numsLeft + 1, preend,
                                          inRoot + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) m[inorder[i]] = i;
        return constructBinaryTree(preorder, inorder, m, 0, n - 1, 0, n - 1);
    }
};
