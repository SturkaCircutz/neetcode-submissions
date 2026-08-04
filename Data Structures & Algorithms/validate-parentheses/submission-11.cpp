class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };
        stack<char> sta; 
        for(auto c : s){
            if(mp.count(c)){
                if(sta.empty() || sta.top() != mp[c]){
                    return false;
                }
                sta.pop();
            }else{
                sta.push(c);
            }
        }
        return sta.empty();
    }
};
