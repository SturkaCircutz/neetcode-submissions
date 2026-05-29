class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dup = -1;
        for(auto n : nums){
            mp[n]++;
            if(mp[n]>1){
                dup = n;
            }
        }
        return dup;
    }
};
