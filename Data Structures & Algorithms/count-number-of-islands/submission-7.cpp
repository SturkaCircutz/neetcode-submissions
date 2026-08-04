class Solution {
public:
    int row, col;
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || r>=row || c < 0 || c >=col || grid[r][c]!='1') return;
        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r, c-1);
    }

};
