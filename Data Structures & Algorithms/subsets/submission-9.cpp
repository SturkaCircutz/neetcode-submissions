class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        backtrack(curr, 0, nums);
        return res;
    }
    void backtrack(vector<int>&curr, int i, vector<int>&nums){
        res.push_back(curr);
        if(i == nums.size()) return;
        for(int j = i; j < nums.size(); j++){
            curr.push_back(nums[j]);
            backtrack(curr, j+1, nums);
            curr.pop_back();
        }
    }
};
