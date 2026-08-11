class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev1=2;
        if(n==1){
            return 1;
        }
        for(int i =3;i<=n;i++){
            int curr=prev2+prev1;
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }
};
