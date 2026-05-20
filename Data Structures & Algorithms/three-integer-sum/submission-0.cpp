class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int f = i+1, e = nums.size()-1;
            while(f<e){
                int check = nums[i]+nums[f]+nums[e];
                if(check == 0 && (find(ans.begin(), ans.end(), vector<int>{nums[i], nums[f], nums[e]}) == ans.end())  ){
                    ans.push_back({nums[i], nums[f], nums[e]});
                }
                if(check < 0){
                    f++;
                }
                else{
                    e--;
                }

            }


        }
        return ans;
    }
};
