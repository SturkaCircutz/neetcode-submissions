class Solution {
public:
    int findMin(vector<int> &nums) {
        int mid = -1;
        int left = 0, right = nums.size()-1;
        while(left <= right){
             mid = (left+right)/2;
            if(nums[mid]<nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[mid];
    }
};
