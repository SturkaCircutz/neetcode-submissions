class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int nk;
    KthLargest(int k, vector<int>& nums) {
        nk = k;
        for(auto n : nums){
            q.push(n);
            if(q.size()>k){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>nk){
            q.pop();
        }
        return q.top();
    }
};
