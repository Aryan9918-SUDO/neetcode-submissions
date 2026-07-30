class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(grid[i][j]==0){
                    q.push({i,j});

                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for(int k =0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr<0 || nr>=row || nc<0 || nc>=col){
                    continue;
                }

                if(grid[nr][nc]!=2147483647){
                    continue;
                }

                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});
            }

        }

        
    }
};
