class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto str : strs){
            res += to_string(str.length()) +"#"+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0; int j = 0;
        while(i < s.length()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, len));
            i = j+1+len;
        }
        return res;
    }
};
