class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> store(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            store[i] = nums[i-1] * store[i-1];
        }
        int prefix = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            store[i] *= prefix;
            prefix *= nums[i];
        }
        return store;
    }
};
