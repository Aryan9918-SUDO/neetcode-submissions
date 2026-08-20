class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int>hold(n);
        vector<int>sold(n);
        vector<int>cooldown(n);

        hold[0]=-prices[0];
        sold[0]=INT_MIN;
        cooldown[0]=0;

        for(int i =1 ;i<n;i++){

        hold[i]=max(hold[i-1],cooldown[i-1]-prices[i]);

        sold[i]=hold[i-1]+prices[i];

        cooldown[i]=max(cooldown[i-1],sold[i-1]);
        }

        return max(sold[n-1],cooldown[n-1]);
        
    }
};
