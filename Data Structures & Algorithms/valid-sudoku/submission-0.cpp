class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size();++i){
            unordered_map<char, int> mp;
            for(int j=0; j<board.size();++j){
            if(board[i][j] == '.') continue;
            mp[board[i][j]]++;
            if(mp[board[i][j]]>1) return false;
        }
        }
        for(int i=0; i<board.size();++i){
            unordered_map<char, int> mp;
            for(int j=0; j<board.size();++j){
            if(board[j][i] == '.') continue;
            mp[board[j][i]]++;
            if(mp[board[j][i]]>1) return false;
        }
        }
        for(int r = 0; r<board.size(); r+=3){
        for(int k = 0; k<board.size(); k+=3){
            unordered_map<char, int> mp;
            for(int i=r; i<3+r;++i){
                for(int j=k; j<3+k;++j){
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]]>1) return false;
        }
        }
        }
        }
        return true;
        
    }
};
