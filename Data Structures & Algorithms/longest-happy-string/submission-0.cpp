class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxheap;
        if(a>0){maxheap.push({a,'a'});}
        if(b>0){maxheap.push({b,'b'});}
        if(c>0){maxheap.push({c,'c'});}

        string ans="";
        while(!maxheap.empty()){
            auto[count1,ch1]=maxheap.top();
            maxheap.pop();
            int n = ans.size();
            if(n>=2 && ans[n-1]==ch1 && ans[n-2]==ch1){
                if(maxheap.empty()){
                    break;
                }
                auto[count2,ch2]=maxheap.top();
                maxheap.pop();
                ans+=ch2;
                count2--;
                 if(count2 > 0) {
                    maxheap.push({count2, ch2});
                }

                
                maxheap.push({count1, ch1});
            }
            else{
                ans+=ch1;
                count1--;
                if(count1 > 0) {
                    maxheap.push({count1, ch1});
                }

            }

        }
        return ans;

    }
};