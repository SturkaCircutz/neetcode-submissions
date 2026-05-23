class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
        }
        int cur = 1;
        int ans = 0;
        for(auto num : mp){
            if(mp.find(num.first+1)!=mp.end()){
                cur++;
                continue;
            }
            else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        return ans;
    }
};
