class Solution {
public:
    set<pair<int, int>> index;
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; ++j){
                if(dfs(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, int row, int col, int curr, string word){
        if(curr == word.length()) return true;
        if(row<0||col<0||row>=ROWS||col>=COLS||word[curr]!=board[row][col]||index.count({row, col})) return false;
        index.insert({row, col});
        bool res = dfs(board, row+1, col, curr+1, word)||
                   dfs(board, row, col-1, curr+1, word)||
                   dfs(board, row, col+1, curr+1, word)||
                   dfs(board, row-1, col, curr+1, word);
        index.erase({row, col});
        return res;
    }
};
