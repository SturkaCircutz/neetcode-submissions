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
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) {
        push(root, 0);
        return ans;
    }
    void push(TreeNode * root, int dep){
        if(!root) return;
        if(dep == ans.size()){
            ans.push_back(vector<int>{});
        }
        if(root) ans[dep].push_back(root->val);
        push(root->left, dep+1);
        push(root->right , dep+1);
    }
};
