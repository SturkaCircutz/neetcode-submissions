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
        if(!root) return "N";
        queue<TreeNode *> que;
        que.push(root);
        string res;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            if(!node){
                res+="N,";
            }
            else{
                res+=to_string(node->val)+",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        queue<TreeNode*> que;
        getline(ss, val, ',');
        if(val == "N") return nullptr;
        TreeNode * node = new TreeNode(stoi(val));
        que.push(node);
        while(getline(ss, val, ',')){
            TreeNode * root = que.front();
            que.pop();
            if(val != "N"){
                root->left = new TreeNode(stoi(val));
                que.push(root->left);
            }
            getline(ss, val, ',');
            if(val != "N"){
                root->right = new TreeNode(stoi(val));
                que.push(root->right);
            }
        }
        return node;
    }
};
