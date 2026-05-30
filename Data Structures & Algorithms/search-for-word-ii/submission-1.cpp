class Solution {
public:
vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int x = board.size(), y = board[0].size();

        for(int k=0; k<words.size(); ++k){
            bool found = false;
        for(int i = x-1; i>=0&&!found; --i){
            for(int j = y-1; j>=0&&!found; --j){
            if(check(board, words[k], i, j, words[k].size(), 0)){
                ans.push_back(words[k]);
                found = true;
            }
            }
        }
        }
        return ans;
                
    }
    bool check(vector<vector<char>>& board, string& word, int x, int y, int size, int csize){
        if(size == csize) return true;
        if(x<0 || y<0 || x>=board.size()||y>=board[0].size()||word[csize]!=board[x][y]) return false;
        auto temp =board[x][y];
        board[x][y]='#';
        bool found= check(board, word, x-1, y, word.length(), csize+1) ||
               check(board, word, x+1, y, word.length(),csize+1) ||
               check(board, word, x, y-1, word.length(),csize+1) ||
               check(board, word, x, y+1, word.length(),csize+1);
        board[x][y]=temp;
        return found;
    }
};
