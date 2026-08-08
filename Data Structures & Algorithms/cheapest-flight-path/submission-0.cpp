class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        // {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> pq;

        pq.push({0, {src, 0}});
        dist[src] = 0;

        while(!pq.empty()) {

            auto it = pq.front();
            pq.pop();

            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stop > k)
                continue;

            for(auto &it : adj[node]) {

                int nextnode = it.first;
                int weight = it.second;

                if(cost + weight < dist[nextnode]) {

                    dist[nextnode] = cost + weight;

                    pq.push({
                        stop + 1,
                        {nextnode, cost + weight}
                    });
                }
            }
        }

        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};