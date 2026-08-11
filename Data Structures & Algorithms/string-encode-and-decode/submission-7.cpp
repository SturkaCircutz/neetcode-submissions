class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto s : strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int l = 0, r = 0;
        vector<string> res;
        while( r< s.size()){

            while(s[r] != '#'){
                r++;
            }
            
            string len = s.substr(l, r-l);
            string curr = s.substr(r+1, stoi(len));
            res.push_back(curr);
            l = r+1+stoi(len);
            r = l;
        }
        return res;
    }
};
