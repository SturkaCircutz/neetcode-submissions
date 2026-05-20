class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 0);
        int id = 0;
        for(int i = 0; i<nums.size(); ++i){
            int res = 1;
            for(int j = 0; j<nums.size(); ++j){
    
                if(j!=i){
                    res *= nums[j];
                }
            }
            out[i]=res;
            id++;
        }
    return out;
    }

};
