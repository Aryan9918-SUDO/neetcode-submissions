class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>rank(26);
        for(int i =0; i<26;i++){
            rank[order[i]-'a']=i;
        }
        for(int i =0;i<words.size()-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            bool founddifference = false;

            int len= min(word1.size(),word2.size());
            for(int j =0;j<len;j++){
                if(word1[j]!=word2[j]){
                    if(rank[word1[j]-'a']>rank[word2[j]-'a']){
                        return false;
                    }
                    founddifference= true;
                    break;
                }
            }
            if(!founddifference && word1.size()>word2.size()){
                return false;
            }
        }
        return true;
    }
};