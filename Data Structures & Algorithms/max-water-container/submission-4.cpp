class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int res = 0;
        while(l < r){
            int size = min(heights[l], heights[r]) * (r-l);
            res = max(size, res);
            if(heights[l]<heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return res;
    }
};
