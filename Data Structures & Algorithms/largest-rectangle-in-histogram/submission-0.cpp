class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int height = 0;
        stack<int> sta;
        int maxi = 0;
        for(int i = 0; i <= heights.size(); i++){
            while(!sta.empty() && (i==heights.size() ||heights[sta.top()]>heights[i])){
                int cur = sta.top();
                sta.pop();
                height = heights[cur];
                int width = sta.empty()?i:i-sta.top()-1;
                maxi = max(maxi, width * height);
            }
            sta.push(i);
        }
        return maxi;
    }
};
