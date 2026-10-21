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
        queue<TreeNode*>q;
        string str = "";
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; ++i){
                TreeNode* head = q.front();
                q.pop();
                if(head){
                    str+=to_string(head->val) + ",";
                    q.push(head->left);
                    q.push(head->right);
                }
                else str+="#,";
            }
        }
        return str;
         
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data<<"\n";
        if(data == "") return NULL;
        queue<TreeNode*>q;
        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        // cout<<s<<"\n";
        TreeNode* head = new TreeNode(stoi(s));
        q.push(head);
        TreeNode* res = head;
        while(!q.empty()){
            TreeNode* node = q.front(); 
            q.pop();
            getline(ss, s, ',');
            // cout<<"first:"<<s<<"\n";
            if(s!="#"){
            node->left = new TreeNode(stoi(s));
            q.push(node->left);
            }else node->left = NULL;

            getline(ss, s, ',');
            // cout<<"second:"<<s<<"\n";
            if(s!="#"){
            node->right = new TreeNode(stoi(s));
            q.push(node->right);
            }else node->right = NULL;
        }
        return res;
    }
};
