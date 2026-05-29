class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n-1][1]=dp[n-1][0]=nums[n-1];
        for(int i = n-2; i>=0; --i){
            dp[i][0]=max(nums[i], dp[i+1][0]+nums[i]);
            dp[i][1]=max(dp[i+1][1], dp[i][0]);
        }
        return dp[0][1];
    }
};
