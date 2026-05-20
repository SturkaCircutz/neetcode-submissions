class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(auto & cha:strs){
            
            encoded_string+=to_string(cha.size());
            encoded_string+="?";
            encoded_string+=cha;

        }
        cout<<encoded_string;
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int count = 0;
        int index = 0;
        while(index<s.size()){
            count = index;
            while(s[count]!='?'){
                count++;
            }
            
           
            int len = stoi(s.substr(index, count-index));
            decoded_strs.push_back(s.substr(count+1, len));
           index = len+count+1;}
        
        return decoded_strs;
    }
};
