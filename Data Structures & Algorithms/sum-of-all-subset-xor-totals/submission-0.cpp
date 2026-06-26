class Solution {
public:
    int ans = 0;

    void solve(int idx, int xr, vector<int>& nums) {
        
        if (idx == nums.size()) {
            ans += xr;
            return;
        }

       
        solve(idx + 1, xr ^ nums[idx], nums);

        
        solve(idx + 1, xr, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(0, 0, nums);
        return ans;
    }
};