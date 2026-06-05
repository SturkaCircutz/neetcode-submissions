class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int time = 0;
        for(auto t : tasks){
            count[t - 'A'] += 1;
        }
        priority_queue<int> maxheap;
        for(auto c : count){
            if(c>0){
                maxheap.push(c);
            }
        }
        queue<pair<int,int>> q;
        while(!maxheap.empty() || !q.empty()){
            time++;
            if(!maxheap.empty()){
                int curr = maxheap.top()-1;
                maxheap.pop();
                if(curr > 0){
                    q.push({curr,time+n});
                }
            }
            if(!q.empty() && q.front().second == time){
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;

    }
};
