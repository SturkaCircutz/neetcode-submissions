class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int first = numbers[l]; int sec = numbers[r];
            if(first + sec == target){
                return vector<int>{l+1, r+1};
            }
            if(first + sec > target){
                r--;
            }
            else{
                l++;
            }

        }
    }
};
