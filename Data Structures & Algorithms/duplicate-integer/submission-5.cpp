class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto [key, val] : mp){
            if(val > 1){
                return true;
            }
        }
        return false;
    }
};