class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            int currentweight =0;
            int daysneeded =1;
            for(int weight : weights){
                if(currentweight+weight<=mid){
                    currentweight+=weight;
                }
                else{
                    daysneeded++;
                    currentweight=weight;
                }
            }
            if(daysneeded<=days){
                ans = mid;
                high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return ans;
               
    }
};