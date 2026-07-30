class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh =0;
        queue<pair<int,int>>q;
        int minutes =0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }

            }
        }
        if(fresh==0){
            return 0;
        }
        while(!q.empty()&&fresh>0){
            int size=q.size();

           for(int j =0;j<size;j++){

            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc=c+dc[k];

                if(nr<0||nr>=row||nc<0||nc>=col){
                    continue;
                }
                if(grid[nr][nc]!=1){
                    continue;
                }
                grid[nr][nc]=2;
                fresh--;
                q.push({nr,nc});
            }
             
           }
           minutes++;
        }
        if(fresh==0){
            return minutes;
        }
        return -1;
        
    }
};
