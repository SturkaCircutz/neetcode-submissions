class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int count = 0;
        int far = 0;
        while( r < nums.size()-1){
            for(int i = l; i <= r; i++){
                far= max(far, nums[i]+i);
            }

            l = r+1;
            r = far;
            count ++;
        }
        return count;
    }
};
