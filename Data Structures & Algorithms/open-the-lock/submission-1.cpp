class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());

        if(dead.count("0000")){
            return -1;
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");

        int moves =0;

        while(!q.empty()){
            int len = q.size();
            
            for(int i =0;i<len;i++){
                string curr = q.front();
                q.pop();
                
                if(curr==target){
                    return moves;
                }
                for(int k=0;k<4;k++){
                    string next = curr;

                   //turning the wheel forward
                    next[k]=(curr[k]=='9')?'0':curr[k]+1;
                    if(!dead.count(next) && !visited.count(next)){
                        q.push(next);
                        visited.insert(next);
                    }

                    //turning the wheel backward
                    next = curr;
                    next[k]=(curr[k]=='0')?'9':curr[k]-1;
                    if(!dead.count(next) && !visited.count(next)){
                        q.push(next);
                        visited.insert(next);
                    }
                }
                
            }
            moves++;
        }
        return -1;
        
    }
};