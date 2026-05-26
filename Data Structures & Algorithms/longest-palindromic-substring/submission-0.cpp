class Solution {
public:
    string longestPalindrome(string s) {
        int reslen =0, residx = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n-1; i>=0; --i){
            for(int j = i; j<n; ++j){
                if(s[i]==s[j] &&(j-i+1<=2 || dp[i+1][j-1] )){ dp[i][j]=true;
                if(reslen < j-i+1){

                    reslen = j-i+1;
                    residx = i;
                }
                }
            }
        }
        return s.substr(residx, reslen);
    }
};
