class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(dfs(cost, dp, 0), dfs(cost,dp, 1));
    }
    int dfs(vector<int>& cost, vector<int> & dp, int i){
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i]!= -1){
            return dp[i];
        }
        dp[i] = cost[i] + min(dfs(cost, dp, i+1), dfs(cost, dp, i+2));
        return dp[i];
    }
};
