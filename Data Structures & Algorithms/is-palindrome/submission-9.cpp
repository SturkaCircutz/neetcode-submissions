class Solution {
public:
    bool isPalindrome(string s) {
    int left =0, right = s.length()-1;
    while(left < right){
        cout<<left<<endl;
        cout<<right<<endl;
        while(left < right && !isalnum(s[left]) ){
            left ++;
        }
        while(left < right && !isalnum(s[right])){
            right--;
        }
        if(left >= right){
            return true;
        }
        if(left < right&& tolower(s[left]) == tolower(s[right])){
            left ++;
            right --;
            continue;
        }
        return false;
    }
    return true;
    }
};
