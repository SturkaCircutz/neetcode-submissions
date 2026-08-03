class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int count = 1;
        int res = 0;
        for(auto n : mp){
            if(mp.find(n.first+1)!=mp.end()){
                count++;
                continue;
            }
            
            res = max(count, res);
            count = 1;
        }
        return res;
    }
};
