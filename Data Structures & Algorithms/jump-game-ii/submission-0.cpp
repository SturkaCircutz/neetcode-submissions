class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0;
        int largest =0;
        int ans = 0;
        while(right<nums.size()-1){
            for(int i = left; i<=right; ++i){
                largest=max(largest, i+nums[i]);

            }
            left = right +1;
            right= largest;
            ans++;
        }
        return ans;
    }
    
};
