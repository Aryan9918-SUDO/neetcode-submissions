class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1= word1.size();
        int l2 = word2.size();
        string s ="";
        int start1 = 0;
        int start2 =0;
        int n = min(l1,l2);
        for(int i =0; i<n;i++){
            s+=word1[i];
            s+=word2[i];


        }
        s+=word1.substr(n);
        s+=word2.substr(n);
        return s;
    }
};