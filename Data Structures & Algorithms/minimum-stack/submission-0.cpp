class MinStack {
public:
    stack<int> stk;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        int mini = INT_MAX;
        stack<int> temp = stk;
        while(!temp.empty()){
            if(temp.top()<mini){
                mini =temp.top();
            }
            temp.pop();
        }
        return mini;
    }
};
