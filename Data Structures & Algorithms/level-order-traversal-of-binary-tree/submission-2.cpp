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
        if(!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i = 0 ; i < size ; ++i){
                TreeNode* head = q.front();
                temp.push_back(head->val);
                q.pop();
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
