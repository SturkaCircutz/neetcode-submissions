class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i< nums.size(); ++i){
            int goal = target - nums[i];
            if(mp.find(goal)!=mp.end()){
                return {mp[goal], i};
            }
            mp[nums[i]]=i;
        }
    }

};
