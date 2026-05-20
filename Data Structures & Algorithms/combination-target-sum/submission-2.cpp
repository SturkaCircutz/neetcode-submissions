class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, cur, 0, target);
        return ans;

    }
    void backtrack(vector<int>& nums, vector<int>& cur, int i, int target){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0 || i >= nums.size()){
            return;
        }
        
        cur.push_back(nums[i]);
        backtrack(nums, cur, i, target-nums[i]);
        cur.pop_back();
        backtrack(nums, cur, i+1, target);
    }
};
