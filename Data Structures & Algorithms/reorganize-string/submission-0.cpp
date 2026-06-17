class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>>maxheap;
        for(auto &it : freq){
            maxheap.push({it.second,it.first});
        }
        string ans ="";
        int prevfreq =0;
        char prevchar ='#';
        while(!maxheap.empty()){
            auto[currfreq,currchar]=maxheap.top();
            maxheap.pop();
            ans+=currchar;
            currfreq--;

            if(prevfreq>0){
                maxheap.push({prevfreq,prevchar});
            }
            prevfreq=currfreq;
            prevchar=currchar;
            
        }
         if(ans.size() != s.size()) {
            return "";
        }

        return ans;


        
    }
};