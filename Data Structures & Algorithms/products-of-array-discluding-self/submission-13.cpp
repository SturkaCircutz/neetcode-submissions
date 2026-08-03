class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            res[i] = nums[i-1] * res[i-1];
        }
        int pre = 1;
        for(int j = nums.size()-1; j >=0; j--){
            res[j] *= pre;
            pre *= nums[j];
        }
        return res; 
    }
};
