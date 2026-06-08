class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(auto interval : intervals){
            int first = interval[0];
            int sec = interval[1];
            int maxin = output.back()[1];
            if(first <= maxin){
                output.back()[1] = max(maxin, sec);
            }else{
                output.push_back(interval);
            }
            
        }
        return output;
    }
};
