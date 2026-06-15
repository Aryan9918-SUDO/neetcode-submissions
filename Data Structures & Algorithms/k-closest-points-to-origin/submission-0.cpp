class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,
        vector<pair<int,vector<int>>>,
        greater<pair<int,vector<int>>>>minheap;
        
        vector<vector<int>>answers;
        for(auto& point :points){
           int x = point[0];
           int y = point[1];
           int dist = x*x + y*y;
           minheap.push({dist,point});
        }
        for(int i =0;i<k;i++){
            
            answers.push_back(minheap.top().second);
            minheap.pop();
        }
        return answers;
        
    }
};
