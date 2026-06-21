class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost =0;
        for(int i =0;i<n;i++){
           totalgas+=gas[i];
           totalcost+=cost[i];
        }
        if(totalcost>totalgas){
            return -1;
        }
        int currentgas =0; int startindex=0;
        for(int i =0;i<n;i++){
            currentgas+=gas[i]-cost[i];
            if(currentgas<0){
                startindex=i+1;
                currentgas =0;
            }
        }
        return startindex;
        
    }
};
