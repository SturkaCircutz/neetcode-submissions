class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        auto j = -1;
        while(res.size()<queries.size()){
            j++;
            auto mini = INT_MAX;
        for(int i = 0; i<intervals.size(); i++){
            int left_i = intervals[i][0], right_i = intervals[i][1];
            if(left_i<=queries[j] && right_i>=queries[j] && right_i-left_i+1 < mini){
                mini = right_i-left_i+1;
                }
            if(mini != INT_MAX && i==intervals.size()-1){
                res.push_back(mini);
            }
            if(i==intervals.size()-1 && mini == INT_MAX){
                res.push_back(-1);
            }
            
        }
        }
        return res;
    }
};
