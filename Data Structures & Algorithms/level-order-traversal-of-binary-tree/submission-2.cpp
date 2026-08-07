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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> curr;
        dfs(root,curr,0);
        return res;
    }
    void dfs(TreeNode * root, vector<int> curr, int level){
        if(!root) return;
        if (res.size() == level){
            res.push_back({});
            }
        res[level].push_back(root->val);
        dfs(root->left, curr, level+1);
        dfs(root->right, curr, level+1);
    }
};
