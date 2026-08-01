class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        int completed =0;

        for( auto &it:prerequisites){
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i =0; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }

        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            completed++;

            for(auto & neighbr: adj[curr]){
                indegree[neighbr]--;
                if(indegree[neighbr]==0){
                    q.push(neighbr);
                }
            }
        }
        if(completed==numCourses){
            return true;
        }
        else{
            return false;
        }
        
    }
};
