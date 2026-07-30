class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // minheap
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto n : nums){
            mp[n]++;
        }
        for(auto i : mp){
            q.push(pair{i.second, i.first});
            if(q.size()>k){
                q.pop();
            }
        }
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
