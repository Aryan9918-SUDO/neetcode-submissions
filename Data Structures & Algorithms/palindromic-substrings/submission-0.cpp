class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i =0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len =2 ;len<=n;len++){
            for(int i =0;i+len<=n;i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
        int count =0;
        int row = dp.size();
        int col = dp[0].size();
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
