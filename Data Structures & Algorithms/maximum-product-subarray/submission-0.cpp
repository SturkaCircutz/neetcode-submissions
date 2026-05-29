class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, INT_MIN));
        int n = nums.size();
        int maxi = nums[n-1];
        dp[n-1][1]=dp[n-1][0]=nums[n-1];
        for(int i = n-2; i>=0; --i){
            dp[i][1]=max({nums[i], nums[i]*dp[i+1][1], nums[i]*dp[i+1][0]});
            dp[i][0]=min({nums[i], nums[i]*dp[i+1][1], nums[i]*dp[i+1][0]});
            maxi = max(maxi, dp[i][1]);
        }
        return maxi;
    }
};
