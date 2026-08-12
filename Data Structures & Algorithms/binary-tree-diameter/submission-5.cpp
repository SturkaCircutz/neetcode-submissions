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
     int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        maxi = max(maxi, left+right);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
    int dfs(TreeNode * root){
        if(!root) return 0;
        return 1+max(dfs(root->left), dfs(root->right));
    }
};
