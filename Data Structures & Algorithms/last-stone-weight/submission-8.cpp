class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto s : stones){
            q.push(s);
        }
        while(q.size() > 1){
            int first = q.top();
            q.pop();
            int sec = q.top();
            q.pop();
            q.push(first-sec);
        }
        return q.top();
        
    }
};
