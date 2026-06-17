class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> arr;
        //{enqueuetime,processingtime,index}
        for(int i =0;i<n;i++){
            arr.push_back({tasks[i][0],tasks[i][1],i});
        }
        //sort by enquque time
        sort(arr.begin(),arr.end());

        //min heap-> {processingtime,index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        vector<int>ans;
        long long time =0;
        int i =0;
        while(i<n || !minheap.empty()){
            if(minheap.empty()&&time<arr[i][0]){
                time = arr[i][0];
            }
            while(i<n && arr[i][0]<=time){
                minheap.push({arr[i][1],arr[i][2]});
                i++;
            }
            auto[processingtime,index]=minheap.top();
            minheap.pop();
            time+=processingtime;
            ans.push_back(index);
        }
        return ans;
        
    }
};