class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        int right = matrix.size() * matrix[0].size() - 1;
        int left = 0;
        while(left <= right){

        int mid = (right + left)/2;
        int row = mid/matrix[0].size(); // the row
        int col = mid % matrix[0].size() ; // the column
        if(matrix[row][col] == target){
            return true;
        }
        if(matrix[row][col] > target){
            right = mid-1; 
        }
        if(matrix[row][col] < target){
            left = mid+1;
        }

        }
        return false;

    }
};
