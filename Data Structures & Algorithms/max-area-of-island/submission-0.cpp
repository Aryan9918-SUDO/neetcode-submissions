class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid){
        int row =grid.size();
        int col = grid[0].size();

        if(i<0 || i>=row || j<0 || j>=col){
            return 0;
        }

        if(grid[i][j]==0){
            return 0;
        }

        grid[i][j]=0;
        return 1+solve(i+1,j,grid)+solve(i-1,j,grid)+solve(i,j+1,grid)
        +solve(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxarea=0;

        for(int i =0;i<row;i++){
            for(int j =0; j<col;j++){
                if(grid[i][j]==1){
                    int area= solve(i,j,grid);
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};
