class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for (int neighbor : adj[node]) {

            // Ignore the edge back to parent
            if (neighbor == parent)
                continue;

            // Cycle found
            if (visited[neighbor])
                return false;

            if (!dfs(neighbor, node, adj, visited))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        // Build graph
        for (auto &it : edges) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Check for cycle
        if (!dfs(0, -1, adj, visited))
            return false;

        // Check if graph is connected
        for (int i = 0; i < n; i++) {

            if (!visited[i])
                return false;
        }

        return true;
    }
};