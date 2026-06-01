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
    vector<int> curr;
    int pdep =-1;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return curr;
    }
    void dfs(TreeNode *root, int dep){
        if(root && dep > pdep){ 
            curr.push_back(root->val);
            pdep = dep;
        }
        if(root){
        dfs(root->right, dep+1);
        dfs(root->left, dep+1);
        }
    }
};
