class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.empty()) return 0;
        vector<int> sub1(nums.begin(), nums.end()-1);
        vector<int> sub2(nums.begin()+1, nums.end());
        return max(help(sub1), help(sub2));
    }
    int help(vector<int> & nums){
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]= max(nums[0], nums[1]);
        for(int i =2; i<nums.size(); ++i){
            dp[i]=max(dp[i-1], dp[i-2] + nums[i]);
            }
        
        return dp[nums.size()-1];
    }
    
};
