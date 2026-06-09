class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        int n = coins.size();
        sort(coins.begin(), coins.end());
        for(int i = 0; i <= coins.size(); i++){
                dp[i][0] = 1;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j<=amount; j++){
                if(coins[i]<=j){
                dp[i][j]=dp[i+1][j];
                dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};
