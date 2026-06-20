class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mpp;
        int n = bills.size();
        int j=0;
        while(j<bills.size()){
            if(bills[j]==5){
                mpp[5]++;

            }
            else if(bills[j]==10){
                if (mpp[5] == 0) return false;
                mpp[5]--;
                mpp[10]++;
            }
            else if(bills[j]==20){
                 if (mpp[10] >= 1 && mpp[5] >= 1) {
                    mpp[10]--;
                    mpp[5]--;
                }
                else if (mpp[5] >= 3) {
                    mpp[5] -= 3;
                }
                else {
                    return false;
                }
            }
            j++;       
        }
        return true; 
    }
};