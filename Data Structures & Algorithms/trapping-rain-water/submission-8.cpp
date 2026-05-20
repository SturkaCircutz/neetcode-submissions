class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int left = 0, right = height.size()-1;
        int lmax = height[left], rmax = height[right];
        int res=0;
        while(left < right){
            if(lmax < rmax){
                left ++;
                lmax = max(lmax, height[left]);
                res+= lmax-height[left];
                
            }
            else{
                right --;
                rmax = max(rmax, height[right]);
                res+= rmax-height[right];
                
            }

        }
        return res;
    }
};
