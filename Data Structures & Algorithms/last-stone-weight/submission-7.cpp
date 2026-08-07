class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sta;
        for(auto s : stones){
            sta.push(s);
        }
        while(sta.size()>1){
            int first = sta.top();
            sta.pop();
            int sec = sta.top();
            sta.pop();
            sta.push(abs(first-sec));
        }
        return sta.top();

    }
};
