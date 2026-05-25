class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        map<char, int> mp;
        for(auto &s:t){
            mp[s]++;
        }
        int l =0;
        map<char, int> temp;
        string output="";
        bool judge = true;
        string res = "";
        for(int r = 0; r < s.length(); ++r){
            temp[s[r]]++;
            res+=s[r]; // store the character
            judge = true;
            for(auto &t:mp){
                if(temp[t.first]<t.second){
                   judge = false;
                   break;
                }
            }
            while(judge){
                if(res.length()<output.length() || output == ""){ 
                    output = res;
                }     

                temp[s[l]]--;
                if(temp[s[l]]==0){
                    temp.erase(s[l]);
                }
                l++;
                
                res.erase(0, 1);
                judge = true;
                for(auto &t:mp){
                if(temp[t.first]<t.second){
                    judge = false;
                    break;
                }}
                
            }      
            }
            
            return output;
        }
        
    
};
