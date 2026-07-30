class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row*col-1;
        while(l <= r){
            int mid = (l+r)/2;
            int first = mid/col, second = mid%col;
            if(matrix[first][second] == target){
                return true;
            }
            else if(matrix[first][second] < target){
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        return false;
    }
};
