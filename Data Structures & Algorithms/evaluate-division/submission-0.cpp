class Solution {
public:
    bool dfs(string curr, string target, unordered_map<string,vector<pair<string,double>>> &adj, unordered_set<string> &visited,double &answers,double product){
        if(curr==target){
            answers=product;
            return true;
        }
        visited.insert(curr);
        for(auto &neighbr:adj[curr]){
           string next = neighbr.first;
           double weight = neighbr.second;

           if(!visited.count(next)){
            if(dfs(next,target,adj,visited,answers,product*weight)){
                return true;
            }

           }

          
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i =0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];
            adj[u].push_back({v,value});
            adj[v].push_back({u,1.0/value});
        }
        vector<double>ans;
        for(auto &it : queries){
            string start = it[0];
            string end = it[1];

            if(!adj.count(start)||!adj.count(end)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string>visited;
            double answers =-1.0;
            dfs(start,end,adj,visited,answers,1.0);
            ans.push_back(answers);
        }
        return ans;
        
    }
};