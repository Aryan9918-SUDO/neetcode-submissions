class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;
        string ch;
        int ans=0;
        for(int i =0;i<n;i++){
            ch=operations[i];
            if(ch !="+" && ch !="C"&&ch!="D"){
                st.push(stoi(ch));
            }
            else if(ch =="+"){
                int t1= st.top();
                st.pop();
                int t2 = st.top();
                st.push(t1);
                int result = t1+t2;
                st.push(result);
            }
            else if(ch=="D"){
                int t=st.top();
                int result = 2*t;
                st.push(result);
            }
            else if(ch=="C"){
                st.pop();
            }
        }
        int x = st.size();
        for(int i =0;i<x;i++){
            int t1 = st.top();
            st.pop();
            ans+=t1;
        }
        return ans;
        
    }
};