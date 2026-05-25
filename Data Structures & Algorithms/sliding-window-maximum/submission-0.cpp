class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size()-k+1; ++i){
            int maxi = nums[i];
            int curr = i;
            
            for(int l = 0; l<k; ++l){
                
                if(nums[curr]>maxi){
                    maxi = nums[curr];
                    cout<<maxi<<endl;
                }
                curr ++;
                
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
