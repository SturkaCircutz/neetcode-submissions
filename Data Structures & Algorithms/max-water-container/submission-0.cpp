class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0, right = heights.size()-1;
        int ans =0, height =0;
        while(left<right){
            height = min(heights[left], heights[right]);
            ans = max(height * (right - left), ans);
            if(heights[left]>heights[right]){
                right--;
            }
            else{
                left++;
            }

        }
        return ans;
    }
};
