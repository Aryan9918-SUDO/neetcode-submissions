class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left =0; //buy day
        int right = 1; // sell day
        int maxprofit=0;
        while(right<n){
            if(prices[right]>prices[left]){
                int profit = prices[right]-prices[left];
                maxprofit = max(profit,maxprofit);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxprofit;
        
    }
};
