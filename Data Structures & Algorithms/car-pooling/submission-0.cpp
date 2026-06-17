class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        for(auto& trip: trips){
            int passenger=trip[0];
            int from = trip[1];
            int to = trip[2];
            events.push_back({from,passenger});
            events.push_back({to,-passenger});

        }
        sort(events.begin(),events.end());
        int currpassenger =0;
        for(auto event:events){
            currpassenger+=event.second;
            if(currpassenger>capacity){
                return false;
            }
        }
        return true;

    }
};