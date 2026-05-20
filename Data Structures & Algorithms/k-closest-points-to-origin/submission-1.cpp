class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>> > maxheap;
        for(auto pt : points){
            int px = pt[0], py=pt[1];
            int eu = pt[0]*pt[0] + pt[1]*pt[1];
            maxheap.push({eu, {pt[0], pt[1]}});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<vector<int>> ans;
        while(maxheap.size()!=0){
            ans.push_back({maxheap.top().second.first, maxheap.top().second.second});
            maxheap.pop();
        }
        return ans;
    }
};
