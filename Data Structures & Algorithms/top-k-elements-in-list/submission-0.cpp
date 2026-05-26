class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int,int>>temp;
        for(auto it:freq ){
            temp.push_back({it.second,it.first});
        }
        vector<int>ans;
        sort(temp.rbegin(),temp.rend());
        for(int i =0; i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};
