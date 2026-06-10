class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int x : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && x<0){
                int top = st.top();
                if(top>abs(x)){
                    destroyed =true;
                    break;
                }
                else if(top<abs(x)){
                    st.pop();
                }
                else{
                    st.pop();
                    destroyed = true;
                    break;
                }

            }
            if(destroyed==false){
                st.push(x);
            }

        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};