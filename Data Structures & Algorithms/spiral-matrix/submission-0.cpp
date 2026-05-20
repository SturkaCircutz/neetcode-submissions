class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans(matrix.size() * matrix[0].size());
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();
        int curr = 0;
        while(top<bottom && right > left){
        for(int i = left; i < right; i++){
            ans[curr++] = matrix[top][i];
        }
        top ++;
        for(int i = top; i< bottom ; i++){
            ans[curr++] = matrix[i][right-1];
        }
        right--;
        if (!(top<bottom && right>left)) break;
        for(int i = right-1; i >= left; i--){
            ans[curr++] = matrix[bottom-1][i];
        }
        bottom --;
        for(int i = bottom-1; i >= top ; i--){
            ans[curr++] = matrix[i][left];
        }
        left++;


        }
        return ans;

    }
};
