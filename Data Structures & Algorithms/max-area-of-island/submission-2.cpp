class Solution {
public:
    int maxi =0;
    int count = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i =0; i<grid.size(); ++i){
            for(int j =0; j<grid[0].size(); ++j){
                if(grid[i][j]==1){
                    count = 0;
                    dfs(grid, i, j);
                    maxi = max(count, maxi);
                }
                
            }
        }
        return maxi;
        
    }
    void dfs(vector<vector<int>>& grid, int x, int y){

        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]!=1){
            return;
        }
        count++;
        grid[x][y]=2;
        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);
    }
};
