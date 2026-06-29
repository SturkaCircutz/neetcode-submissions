class Solution {
public:
    vector<vector<int>> dir = {
        {1,0}, {0,1},{-1,0}, {0,-1},
    }; // four directions
    vector<vector<int>> res;
    int ROWS, COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> alt(ROWS, vector<bool>(COLS, false));
        for(int i = 0; i < COLS; i++){
            dfs(0, i, heights, pac);
            dfs(ROWS-1, i, heights, alt);
        }
        for(int i = 0; i < ROWS; i++){
            dfs(i, 0, heights, pac);
            dfs(i, COLS-1, heights, alt);
        }
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; ++j){
                if(pac[i][j] && alt[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>> & ocean){
        ocean[r][c] = true;
        for(auto&h:dir){
            int nr = r+h[0];
            int nc = c+h[1];
            if(nr >= 0 && nr<heights.size() && nc >= 0 && nc<heights[0].size() 
            && !ocean[nr][nc] && heights[nr][nc] >=heights[r][c]){
                dfs(nr, nc, heights, ocean);
            }
        }
        
    }
};
