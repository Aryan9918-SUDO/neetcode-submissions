class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        queue<int>q;
        vector<int>indegree(n,0);

        if(n==1){
            return {0};
        }

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        for(int i =0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int remaining_nodes = n;
        while(remaining_nodes>2){
            int size = q.size();
            remaining_nodes -=size;
            for(int i =0;i<size;i++){
                int leaf = q.front();
                q.pop();
                for(auto &neighbr : adj[leaf]){
                    indegree[neighbr]--;
                    if(indegree[neighbr]==1){
                        q.push(neighbr);
                    }

                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};