class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s:tokens){
            if(s == "-" || s == "+" || s == "*" ||s == "/" ){
                int num1 = stk.top();
                    stk.pop();
                int num2 = stk.top();
                    stk.pop();
                if(s == "+"){
                    num1 += num2;
                    stk.push(num1);
                }
                if(s == "-"){
                    num2 -= num1;
                    stk.push(num2);
                }
                if(s == "*"){
                    num1 *= num2;
                    stk.push(num1);
                }
                if(s == "/"){
                    num2 /= num1;
                    stk.push(num2);
                }
            }
            else{
                auto k = stoi(s);
                stk.push(k);
            }

            
        }
        return stk.top();
    }
};
