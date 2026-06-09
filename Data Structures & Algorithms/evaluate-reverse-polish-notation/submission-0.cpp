class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        
        for(string ch : tokens){
            if(ch!="+"&& ch!="-"&&ch!="*"&&ch!="/"){
                st.push(stoi(ch));

            }
            else{
                if(ch=="+"){
                    int t1= st.top();
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    int result = t1+t2;
                    st.push(result);
                }
                else if(ch=="-"){
                    int t1= st.top();
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    int result = t2-t1;
                    st.push(result);
                }
                else if(ch=="/"){
                    int t1= st.top();
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    int result = t2/t1;
                    st.push(result);
                }
                else if(ch=="*"){
                    int t1= st.top();
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    int result = t1*t2;
                    st.push(result);
                }
            }

        }
        return st.top();
        
    }
};
