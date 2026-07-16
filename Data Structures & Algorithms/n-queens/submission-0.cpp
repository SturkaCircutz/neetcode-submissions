class Solution {
public:
    unordered_set<int> neg;
    unordered_set<int> pos;
    unordered_set<int> col;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        track(n, 0, board);
        return res;
    }
    void track(int n, int r, vector<string>& board){
        if(r == n){
            res.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            if(pos.count(r+i) || col.count(i) || neg.count(r-i)){
                continue;
            }
            pos.insert(r+i);
            neg.insert(r-i);
            col.insert(i);
            board[r][i] = 'Q';
            track(n, r+1, board);
            pos.erase(r+i);
            neg.erase(r-i);
            col.erase(i);
            board[r][i] = '.';
        }
    }
};
