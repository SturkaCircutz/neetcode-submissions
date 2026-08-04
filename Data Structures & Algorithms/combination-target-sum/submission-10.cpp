class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, target, curr, 0);
        return res;

    }
    void backtrack(vector<int>& nums, int target, vector<int> curr, int j){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = j; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, target-nums[i], curr, i);
            curr.pop_back();
        }
    }
};
