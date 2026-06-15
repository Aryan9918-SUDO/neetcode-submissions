class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char task : tasks){
            freq[task]++;
        }
        priority_queue<int>maxheap;
        for(auto& it : freq){
            maxheap.push(it.second);
        }

        queue<pair<int,int>>q;
        int time =0;
        while(!maxheap.empty()||!q.empty()){
            time++;
            if(!q.empty()&& q.front().second==time){
                maxheap.push(q.front().first);
                q.pop();
            }
            if(!maxheap.empty()) {
                int count = maxheap.top();
                maxheap.pop();
                count--;
                if(count > 0) {
                    q.push({count, time + n+1});
                }
            }
        }
        return time;
        
    }
};
