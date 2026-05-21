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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(ans, root);
        return ans;
    }
    int dfs(int &ans, TreeNode * root){
        if(!root) return 0;
        int left = dfs(ans, root->left);
        int right = dfs(ans, root->right);
        ans = max(left + right, ans);
        return 1+max(left, right);
    }
};
