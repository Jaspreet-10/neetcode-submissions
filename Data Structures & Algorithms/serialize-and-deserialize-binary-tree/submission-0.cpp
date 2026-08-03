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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) res+="#,";
            else res+=to_string(node->val) + ",";
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<res<<"\n";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        queue<TreeNode*>q;
        stringstream str(data);
        string s;
        getline(str, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(str, s, ',');
            if(s == "#"){
                node->left = NULL;
            }
            else{
                TreeNode*leftNode = new TreeNode(stoi(s));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(str, s, ',');
            if(s == "#"){
                node->right = NULL;
            }
            else{
                TreeNode*rightNode = new TreeNode(stoi(s));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
