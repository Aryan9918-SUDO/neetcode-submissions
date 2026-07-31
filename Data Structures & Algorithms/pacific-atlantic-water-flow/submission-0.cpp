class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& heights,
        vector<vector<bool>>& visited){
            int row=heights.size();
            int col = heights[0].size();

            visited[r][c]=true;

            int dr[]={1,-1,0,0};
            int dc[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr<0||nr>=row||nc<0||nc>=col){
                    continue;
                }
                if(visited[nr][nc]){
                    continue;
                }
                if(heights[nr][nc]<heights[r][c]){
                    continue;
                }
                dfs(nr,nc,heights,visited);
            }
    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>>pacific(row,vector<bool>(col,false));
        vector<vector<bool>>atlantic(row,vector<bool>(col,false));

        for(int i =0;i<col;i++){
            dfs(0,i,heights,pacific); // for pacific top row
        }
        for(int j=0;j<row;j++){
            dfs(j,0,heights,pacific); //for pacific left col
        }
        for(int k=0;k<row;k++){
            dfs(k,col-1,heights,atlantic);  //for atlantic right col
        }
        for(int l=0;l<col;l++){
            dfs(row-1,l,heights,atlantic); // for atlantic bottom row
        }

        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
