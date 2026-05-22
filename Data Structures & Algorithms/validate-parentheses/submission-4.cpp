class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mp ={
            {'}', '{'},
            {']', '['},
            {')', '('},
        };
        for(auto c:s){
            if(mp.count(c)){
                if(!stack.empty() && stack.top()==mp[c]){
                stack.pop();
                }else{
                    return false;
                }
            }
            else{
                stack.push(c);
            }



        }
        return stack.empty();
    }
};
