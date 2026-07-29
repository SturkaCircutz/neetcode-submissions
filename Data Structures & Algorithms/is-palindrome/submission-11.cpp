class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(auto c : s){
            if(isalnum(c)){
                if(isalpha(c)){
                    res+=tolower(c);
                    continue;
                }
                res+=c;
            }
        }
         int l = 0, r = res.size()-1;
        while(l < r){
            if(res[l]!=res[r]){
                return false;
            }
            l++;
            r--;

        }
        return true;
    }
};
