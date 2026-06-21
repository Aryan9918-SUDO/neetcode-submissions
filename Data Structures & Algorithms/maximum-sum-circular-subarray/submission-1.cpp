class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long maxsum=nums[0];
        long long sum =0;
        long long totalsum=0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            totalsum+=nums[i];
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }


        }
        long long minsum=nums[0];
        long long currsum=0;
        for(int i =0;i<n;i++){
            currsum+=nums[i];
            minsum=min(minsum,currsum);
            if(currsum>0){
                currsum=0;
            }
        }
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,totalsum-minsum);
        
    }
};