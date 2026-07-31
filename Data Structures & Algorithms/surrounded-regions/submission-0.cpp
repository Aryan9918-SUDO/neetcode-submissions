class Solution {
public:
    void dfs(int r, int c ,vector<vector<char>>& board){
        int row=board.size();
        int col=board[0].size();
        board[r][c]='#';

        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        for(int k =0;k<4;k++){
            int nr = r+dr[k];
            int nc = c+dc[k];

            if(nr<0||nr>=row||nc<0||nc>=col){
                continue;
            }
            if(board[nr][nc]!='O'){
                continue;
            }
            dfs(nr,nc,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i =0;i<row;i++){ //for left col
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
        }
        for(int i =0;i<col;i++){ //for top row
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
        }
        for(int i =0;i<col;i++){ //for bottom row
            if(board[row-1][i]=='O'){
                dfs(row-1,i,board);
            }
        }
        for(int i =0;i<row;i++){ //for right col
            if(board[i][col-1]=='O'){
                dfs(i,col-1,board);
            }
        }
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
