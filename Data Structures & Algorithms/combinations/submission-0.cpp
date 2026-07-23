class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k, int ind,vector<int>&nums,vector<int>&current){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        if(ind == nums.size()) return;
        
        
        current.push_back(nums[ind]);
        solve(k,ind+1,nums,current);
        current.pop_back();

        solve(k,ind+1,nums,current);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        vector<int>nums;
        
        for(int i =1;i<=n;i++){
            nums.push_back(i);
        }
        solve(k,0,nums,current);
        return ans;
        
    }
};