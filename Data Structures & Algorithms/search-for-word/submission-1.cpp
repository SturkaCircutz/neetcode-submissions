class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> ans;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for(int i =0; i<ROWS; ++i){
            for(int j =0; j<COLS; ++j){
                if(dfs(board,i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, int row, int col, int curr,string word){
        if(curr == word.length()){
            return true;
        }
        if(row<0 || col<0 || row>=ROWS || col>=COLS||board[row][col]!=word[curr]|| ans.count({row, col})){
            // avoid situation like this A -> B -> A
            // which makes the path going back to count a again.
            // in the case of word = aba, and path aba it will return true which is not correct.
            return false;
        }
        // set dont have push back
        ans.insert({row, col});
        bool res = dfs(board, row+1, col, curr+1, word) ||dfs(board, row-1, col, curr+1, word)
                || dfs(board, row, col+1, curr+1, word) ||dfs(board, row, col-1, curr+1, word);
        ans.erase({row, col});
        return res;
    }
};
