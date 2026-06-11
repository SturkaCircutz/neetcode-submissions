class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> mp(n+1);
        mp[0][0] = 1;
        for(int i = 0; i <n; i++){
            for(auto d : mp[i]){
                mp[i+1][d.first-nums[i]] += d.second;
                mp[i+1][d.first+nums[i]] += d.second;
            }
        }
        return mp[n][target];
    }
};
