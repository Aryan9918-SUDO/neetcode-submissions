class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // Minimum cost to connect each node
        vector<int> minCost(n, INT_MAX);

        // Whether node is already included in MST
        vector<bool> visited(n, false);

        // Min Heap -> {cost, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});
        minCost[0] = 0;

        int ans = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int node = curr.second;

            // Ignore if already included
            if (visited[node])
                continue;

            visited[node] = true;
            ans += cost;

            // Try connecting every other point
            for (int next = 0; next < n; next++) {

                if (visited[next])
                    continue;

                int newCost =
                    abs(points[node][0] - points[next][0]) +
                    abs(points[node][1] - points[next][1]);

                if (newCost < minCost[next]) {

                    minCost[next] = newCost;

                    pq.push({newCost, next});
                }
            }
        }

        return ans;
    }
};