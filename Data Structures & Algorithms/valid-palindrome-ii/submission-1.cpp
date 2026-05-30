class Solution {
public:
    bool ispal(string &s, int low,int high){
        while(low<high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;

        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int start =0;
        int end = n-1;
        
        while(start<end){
            while(start<end && !isalnum(s[start])){
                start++;
            }
            while(start<end && !isalnum(s[end])){
                end--;
            }
            if(s[start]!=s[end]){
               return ispal(s,start+1,end)||
                      ispal(s,start,end-1);
            }
            start++;
            end--;
        }
        return true;
        
    }
};