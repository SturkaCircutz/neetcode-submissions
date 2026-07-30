class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto s : strs){
            res+=to_string(s.size())+'#'+s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int l = 0;
        int r = 0;
        vector<string> res;
        while(l < s.size()){
            r = l;
            while(s[r] != '#'){
                r++;
            }
            int num = stoi(s.substr(l, r-l)); // how long is a word
            res.push_back(s.substr(r+1, num));
            l = r+1+num;
        }
        return res;
    }
};
