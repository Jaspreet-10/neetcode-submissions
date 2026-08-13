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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* r = q.front();
                v.push_back(r->val);
                q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            res.push_back(v);
        }
        return res;
    }
};
