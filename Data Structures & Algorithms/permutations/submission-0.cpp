class Solution {
public:
    void find_permute(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,vector<int>&freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                find_permute(ds,nums,ans,freq);
                ds.pop_back();
                freq[i]=0;

            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int>freq(nums.size(),0);
        find_permute(ds,nums,ans,freq);
        return ans;
    }
};
