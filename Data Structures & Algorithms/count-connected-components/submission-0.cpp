class Solution {
public:
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& adj){
        visited[node]=true;

        for(auto &it : adj[node]){
            if(!visited[it]){
              dfs(it,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        int connected =0;

        vector<vector<int>>adj(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i =0;i<n;i++){
            if(!visited[i]){
                connected++;
                dfs(i,visited,adj);
            }
        }
        return connected;
    }
};
