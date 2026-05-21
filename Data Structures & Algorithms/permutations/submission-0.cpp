class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> cur;
    comp(cur, nums);
    return ans;
    }
    void comp(vector<int>cur, vector<int>&nums){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){

            if(find(cur.begin(), cur.end(), nums[i])==cur.end()){

            cur.push_back(nums[i]);
            comp(cur,nums);
            cur.pop_back();

            }
            
        }
    }
};
