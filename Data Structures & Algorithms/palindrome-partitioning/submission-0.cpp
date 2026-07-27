class Solution {
public:
    bool ispalindrome(string& s, int left,int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int index,string& s,vector<string>& ds, vector<vector<string>>& ans){
        if(index==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i =index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,s,ds,ans);
        return ans;
        
    }
};
