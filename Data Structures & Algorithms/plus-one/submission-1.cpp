class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ten = 10;
        long long res = digits[digits.size()-1];
        for(int i = digits.size()-2; i>=0; --i){ // transfer this to a number
            res += ten * digits[i];  // tenth addition
            ten = 10 * ten; // next iteration
        }
        res ++; 
        vector<int> ans;
        while(res!=0){
            int digit = res %10;
            res /= 10;
            ans.push_back(digit);

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
