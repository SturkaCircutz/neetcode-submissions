class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right){
            int x = numbers[left] + numbers[right];
            if(x==target){
                return vector<int>{left + 1, right +1 };
            }
            if(x>target){
                right --;
            }
            else{
                left++;
            }
        }

    }
};
