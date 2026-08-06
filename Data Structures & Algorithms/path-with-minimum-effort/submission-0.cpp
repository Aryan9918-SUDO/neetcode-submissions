class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> effort(row,vector<int>(col,INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        effort[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int curreffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            if(r == row-1 && c == col-1){
                return curreffort;
            }
            for(int k =0; k<4;k++){
                int nr = dr[k]+r;
                int nc = dc[k]+c;
                if(nr < 0 || nr >= row || nc < 0 || nc >= col){
                     continue;
                }
                int edgeweight = abs(heights[r][c]-heights[nr][nc]);
                int neweffort = max(curreffort,edgeweight);
                if(neweffort< effort[nr][nc]){
                   effort[nr][nc]=neweffort;
                   pq.push({neweffort,{nr,nc}});
                }
            }
        }
        return 0;
        
    }
};