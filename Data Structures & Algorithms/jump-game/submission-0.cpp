class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int maxjump =0;
        for(int i =0;i<n;i++){
            if(i>maxjump){
                return false;
            }
            int jump =nums[i]+i;
            maxjump=max(maxjump,jump);
            if(maxjump>=n-1){
                return true;
            }
        }
        return false;
    }
};
