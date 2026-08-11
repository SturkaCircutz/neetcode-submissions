class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(nums, curr, 0);
        return res;
    }
    void dfs(vector<int> & nums, vector<int> & curr, int j){
        res.push_back(curr);
        if(j == nums.size()) return;
        for(int i = j; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, curr, i+1);
            curr.pop_back();
        }
    }
};
