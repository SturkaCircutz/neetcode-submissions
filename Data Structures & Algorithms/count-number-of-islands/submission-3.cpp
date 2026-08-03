class Solution {
public:
    int count = 0;
    int row , col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>> & grid, int x, int y){
        if(x >= row || x <0 || y>=col || y<0 || grid[x][y]!='1'){
        return;     
        }
        grid[x][y] = '#';
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }
};
