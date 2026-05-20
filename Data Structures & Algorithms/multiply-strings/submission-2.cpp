class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size(), 0);
        string ans;
        int sum = 0;
        for(int i = num1.size()-1; i>=0; --i){
            for(int j = num2.size()-1; j>=0; --j){
            int x = num1[i] - '0';
            int y = num2[j] - '0';
            int z = x*y ;
            z += res[i+j+1];
            sum = z %10;
            int carry = z/10;
            res[i+j+1] = sum;
            res[i+j] += carry;
        }
        }
        for(int num : res){
            if(!(ans.empty() && num==0))
            ans += char(num+'0');
        }
        if(num1 == "0" || num2 == "0") return "0";
    return ans;
    }
    
};
