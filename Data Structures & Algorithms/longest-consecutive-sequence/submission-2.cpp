class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int maxi = 0;
        int count = 1;
        for(auto n : nums){
            mp[n]++;
        }
        for(auto n : mp){
            if(mp.find(n.first+1)!=mp.end()){
                count++;
                continue;
            }
            maxi = max(maxi, count);
            count = 1;
        }
        return maxi;
    }
};
