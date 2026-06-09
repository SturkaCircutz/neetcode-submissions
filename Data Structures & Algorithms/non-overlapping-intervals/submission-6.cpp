class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int count = 1;
        int i = 0;
        while(count < intervals.size()){
            int first = intervals[count][0];
            int max = ans.back()[1];
            if(first < max){
                if(intervals[count][1]<max){
                    ans.back() = intervals[count];
                }
                
                i++;
            }
            else{
                ans.push_back(intervals[count]);
                }
            count ++;
        }
        return i;
    }
};
