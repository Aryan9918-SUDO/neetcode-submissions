class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        int completed =0;
        vector<int>ans;

        for(auto &it : prerequisites){
            int course =it[0];
            int prereq =it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            completed++;
            ans.push_back(curr);

            for(auto &neighbr:adj[curr]){
                indegree[neighbr]--;
                if(indegree[neighbr]==0){
                    q.push(neighbr);
                }
            }
           
        }
        if(completed==numCourses){
            return ans;
        }
        else{
            return {};
        }

        
    }
};
