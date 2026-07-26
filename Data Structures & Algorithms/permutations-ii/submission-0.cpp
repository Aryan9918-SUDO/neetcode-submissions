class Solution {
public:
    void solve(vector<int>& freq,
               vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans){

        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){

            if(freq[i]) continue;

            if(i>0 && nums[i]==nums[i-1] && !freq[i-1])
                continue;

            ds.push_back(nums[i]);
            freq[i]=1;

            solve(freq,nums,ds,ans);

            freq[i]=0;
            ds.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(),0);

        solve(freq,nums,ds,ans);

        return ans;
    }
};