class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       int total =0;
       for(int num: nums){
         total+=num;
        }
        if(abs(target)>total){
           return 0;
        }
        if((total+target)%2!=0){
            return 0; 
        }

        int subtarget = (total+target)/2;
        vector<int>dp(subtarget+1,0);
        dp[0]=1;
        for(int num: nums){
            for(int i = subtarget; i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[subtarget];

    }
};
