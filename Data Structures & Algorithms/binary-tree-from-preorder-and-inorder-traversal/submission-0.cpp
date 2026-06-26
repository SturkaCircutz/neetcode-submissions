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
    int count = 0;
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i; 
        }
        return dfs(preorder, 0, inorder.size()-1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l>r) return nullptr;
        int root_val = preorder[count++];
        TreeNode * nu = new TreeNode(root_val);
        int mid = mp[root_val];
        nu->left = dfs(preorder, l, mid-1); 
        nu->right = dfs(preorder, mid+1, r); 
        return nu;
    }
};
