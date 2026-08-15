class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int answer=nums[0];
        int maxproduct=nums[0];
        int minproduct = nums[0];

        for(int i =1;i<n;i++){
            int newmax = max({nums[i],
                            maxproduct*nums[i],
                            minproduct*nums[i]});
            int newmin = min({nums[i],
                            maxproduct*nums[i],
                            minproduct*nums[i]});
            maxproduct = newmax;
            minproduct = newmin;
            answer=max(maxproduct,answer);

        }
        return answer;
        
    }
};
