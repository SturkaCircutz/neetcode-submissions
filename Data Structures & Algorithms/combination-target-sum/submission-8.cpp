class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(curr, 0, target, nums);
        return ans;
    }
    void dfs(vector<int>& curr, int i, int target, vector<int>& nums){
        if(target == 0)
            ans.push_back(curr);
        for(int j = i ; j<nums.size(); ++j){
            if(nums[j] > target){
                return;
            }

            curr.push_back(nums[j]);
            dfs(curr, j, target-nums[j], nums);
            curr.pop_back();
        }
    }
};

