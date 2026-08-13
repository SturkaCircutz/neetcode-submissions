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
    unordered_map<int, int> mp;
    int count = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < preorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size()-1);
        
    }
        TreeNode *dfs(vector<int> & preorder, vector<int> & inorder, int l, int r){
            if(l > r) return nullptr;
            int mid = mp[preorder[count]];
            TreeNode * nu = new TreeNode(preorder[count]);
            count++;
            nu->left = dfs(preorder, inorder, l, mid-1);
            nu->right = dfs(preorder, inorder, mid+1, r);
            return nu;
        
    }

};
