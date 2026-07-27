class Solution {
public:
    //n=row , m=col
    bool dfs(vector<vector<char>>& board, string& word, int n, int m, int index){
        if(index==word.size()){
            return true;
        }
        if(n<0||m<0||n>=board.size()||m>=board[0].size()) return false;

        if(board[n][m]!=word[index]) return false;

        char temp=board[n][m];
        board[n][m]='#';

        bool found =(dfs(board,word,n+1,m,index+1)||
                     dfs(board,word,n-1,m,index+1)||
                     dfs(board,word,n,m+1,index+1)||
                     dfs(board,word,n,m-1,index+1));
        board[n][m]=temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<row;i++){
            for(int j =0;j<col;j++){
                if(dfs(board,word,i,j,0)){
                return true;
                }
            }
        }
        return false;
        
    }
};
