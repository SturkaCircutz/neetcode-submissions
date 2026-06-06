class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int fresh = 0;
        int time = 0;
        for(int i = 0; i<grid.size(); ++i){
            for(int j = 0; j<grid[0].size(); ++j){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        vector<vector<int>> dir = {
            {0,1}, {-1,0}, {1,0}, {0,-1}
        } ;
        while(!que.empty() && fresh > 0){
            int len = que.size();
            for(int i = 0; i<len; i++){
            auto curr = que.front();
            que.pop();
            int x = curr.first, y = curr.second;
            for(auto & d : dir){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx >= 0 && ny >= 0 && nx<grid.size() && ny<grid[0].size() &&grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    que.push({nx, ny});
                    fresh--;
                }
            }
            
            }
            time++;
            
        }
        return fresh == 0 ? time : -1;
    }
};
