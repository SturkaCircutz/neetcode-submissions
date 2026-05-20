class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f = 0, e = nums.size();
        int mid = (f+e)/2;
        if (nums.empty()) {
            return -1;
        }
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            
            vector <int> sub(nums.begin()+mid+1, nums.end());
            int res = search(sub,target);
            if(res==-1){
                return -1;
            }
            return res+mid+1;
        }
        else{
            vector <int> sub(nums.begin(), nums.begin()+mid);
            return search(sub, target);
        }
        return -1;
    }
};
