class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int stone : stones){
            maxheap.push(stone);
        }
        int n = stones.size();
        while(maxheap.size()>1){
            int t1 = maxheap.top();
            maxheap.pop();
            int t2 = maxheap.top();
            maxheap.pop();
            if(t1 != t2) {
                maxheap.push(t1 - t2);
            }
        }
         if(maxheap.empty()) {
            return 0;
        }
        return maxheap.top();
        
    }
};
