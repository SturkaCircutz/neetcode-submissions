class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxl = nums[0];
        for(auto n : nums){
            if(curr < 0) curr = 0;
            curr += n;
            maxl = max(maxl, curr);
        }
        return maxl;
    }
};
