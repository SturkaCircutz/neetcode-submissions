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
    int pdep = -1;
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode * root, int dep){
        if(!root) return;
        if(root && dep > pdep){
            res.push_back(root->val);
            pdep = dep;
        }
        dfs(root->right, dep+1);
        dfs(root->left, dep+1);
    }
};
