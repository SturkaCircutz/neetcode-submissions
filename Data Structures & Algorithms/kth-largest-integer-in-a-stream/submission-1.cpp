class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > ans;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto num : nums){
            ans.push(num);
            if(ans.size()>k){
                ans.pop();
            }
        }
    }
    
    int add(int val) {
        ans.push(val);
        if(ans.size()>k){
            ans.pop();
        }
        return ans.top();
    }
    
};
