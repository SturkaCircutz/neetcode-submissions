class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        comp(nums, cur, 0);
        return ans;
    }
    void comp(vector<int>nums, vector<int> cur, int index){
        if(find(ans.begin(), ans.end(), cur)==ans.end())
        ans.push_back(cur);
        for(int i = index; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            comp(nums, cur, i+1);
            cur.pop_back();
        }

    }
};
