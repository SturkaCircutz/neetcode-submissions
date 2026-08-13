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
    int maxi = INT_MIN;
    int count = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, maxi);
        return count;

    }
    void dfs(TreeNode * curr, int maxi){
        if(!curr) return;
        if(curr->val >= maxi){
            count++;
        }
        maxi = max(maxi, curr->val);
        dfs(curr->left, maxi);
        dfs(curr->right, maxi);
    }
};
