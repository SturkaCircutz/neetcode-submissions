class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(auto num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;
        for(auto item : mp){
            heap.push({item.second, item.first});
            if(heap.size()>k){
                heap.pop();
            }
        }
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;

    }
};
