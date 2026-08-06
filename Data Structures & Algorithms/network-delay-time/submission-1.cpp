class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //distance array
        vector<int>dist(n+1,INT_MAX);

        //adjacency matrix
        vector<vector<pair<int,int>>>adj(n+1);

        //min heap -> {distance, node}
        priority_queue< 
              pair<int,int>,
              vector<pair<int,int>>,
              greater<pair<int,int>>
              >pq;
        for(auto &it:times){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            adj[u].push_back({v,time});
            
        }
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currdist = curr.first;
            int node = curr.second;

            if(currdist>dist[node]){
                continue;
            }

            for( auto &it : adj[node]){
                int nextnode= it.first;
                int weight = it.second;

                int newdist = currdist+weight;
                if(newdist<dist[nextnode]){
                    dist[nextnode]=newdist;
                    pq.push({newdist,nextnode});
                }
            }

        }
        int ans =0;
        for(int i =1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(dist[i],ans);
        }
        return ans;
        
    }
};
