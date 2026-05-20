class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que;
        vector<int> ans;
        unordered_map<int, int> times;
        for(auto & num :nums){
            times[num]++;
        }
        for(auto & num : times){
            que.push({num.second, num.first});
            if(que.size()>k){
                que.pop();
            }
        }
        while(!que.empty()){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};
