class Solution {
public:
    int rows , cols;
    vector<vector<bool>> mp;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        mp = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i = 0; i < cols; ++i){
            dfs(board, 0, i);
            dfs(board, rows-1, i);
        }
        for(int j = 0; j < rows; ++j){
            dfs(board, j, cols-1);
            dfs(board, j, 0);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mp[i][j] == false && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board,int r, int c){
        if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == 'O'){
            if(mp[r][c]) return;
            mp[r][c] = true;
            dfs(board, r-1, c);
            dfs(board, r, c-1);
            dfs(board, r+1, c);
            dfs(board, r, c+1);
        } 
        return; 
    }
};
