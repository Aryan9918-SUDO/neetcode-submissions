class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxsum =nums[0];
        long long sum =0;
        int n = nums.size();
        for(int i  =0;i<n;i++){
            sum+=nums[i];
            maxsum = max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        
        return maxsum;


    }
};
