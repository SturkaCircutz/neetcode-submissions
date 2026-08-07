class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> q;
        vector<vector<int>> res;
        for(auto p : points){
            double dis = p[0]*p[0] + p[1]*p[1];
            q.push({dis, {p[0], p[1]}});
            if(q.size() > k){
                q.pop();
            }

        }
        for(int i = 0; i < k; i++){
            res.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        return res;
    }
};
