class Solution {
public:
    int maxArea(vector<int>& heights) {
        int val = 0, l = 0, r = heights.size()-1;
        while( l < r){
            int curr = min(heights[r], heights[l]) * (r-l);
            val = max(val, curr);
            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return val;
    }
};
