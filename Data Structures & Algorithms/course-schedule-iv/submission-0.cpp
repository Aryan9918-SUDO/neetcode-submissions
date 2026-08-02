class Solution {
public:
    void dfs(int source, int node,
             vector<vector<int>>& adj,
             vector<vector<bool>>& reachable) 
    {
            for (int neighbor : adj[node]) {

              if (!reachable[source][neighbor]) {

                reachable[source][neighbor] = true;

                dfs(source, neighbor, adj, reachable);
               }
            }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            int prereq = it[0];
            int course = it[1];
            adj[prereq].push_back(course);
        }
        
        vector<vector<bool>> reachable(numCourses,vector<bool>(numCourses,false));
        for(int i =0;i<numCourses;i++){
            dfs(i,i,adj,reachable);
        }
        vector<bool>ans;

        for(auto &it : queries){
           int u=it[0];
           int v =it[1];
           ans.push_back(reachable[u][v]); 
        }
        return ans;
    }
};