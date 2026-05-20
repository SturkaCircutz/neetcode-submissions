class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, target, cur, 0);
        return ans;
    }
    void dfs(vector<int>&nums, int target, vector<int> &cur, int i){
        if(target == 0){
            ans.push_back(cur);
        }
        for(int j = i; j<nums.size(); ++j){
            if(nums[j]>target){
                return;
            }
            cur.push_back(nums[j]);
            dfs(nums, target-nums[j], cur,j);
            cur.pop_back();
        }
    }
};
