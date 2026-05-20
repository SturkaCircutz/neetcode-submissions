class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> store(num1.size()+num2.size());
        string ans="";
        // max is two mul size
        for(int i = num1.size()-1; i >=0 ; --i){
            for(int j = num2.size()-1; j >= 0; --j){
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                int z = x * y;
                z = z + store[i+j+1];
                int sum = z % 10;
                int carr = z / 10;
                store[i+j] += carr;
                store[i+j+1] = sum;
            }
        }
        for(auto num : store){
            cout<<num<<endl;
            if(num == 0 && ans.empty() ) continue;
            ans += char(num + '0');
        }
        return ans;
    }

};
