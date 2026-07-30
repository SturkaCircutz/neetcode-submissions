class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto n : nums){
            if(mp.find(n) != mp.end()) return true; 
            mp.insert(n);
        }
        return false;
    }
};