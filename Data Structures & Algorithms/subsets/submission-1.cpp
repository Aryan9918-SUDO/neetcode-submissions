class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, vector<int>& nums, vector<int>& current) {
        // Base case: all elements have been considered
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Include nums[index]
        current.push_back(nums[index]);
        solve(index + 1, nums, current);

        // Backtrack
        current.pop_back();

        // Choice 2: Exclude nums[index]
        solve(index + 1, nums, current);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        solve(0, nums, current);
        return ans;
    }
};