class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, curr, 0);
        return res;
    }
    void dfs(vector<int>&nums, vector<int> & curr, int i){
        if(find(res.begin(), res.end(), curr) == res.end()) 
        res.push_back(curr);
        if(i == nums.size()) return;
        for(int j = i; j < nums.size(); j++){
            curr.push_back(nums[j]);
            dfs(nums, curr, j+1);
            curr.pop_back();
        }
    }
};
