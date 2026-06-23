class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool x = false;
        bool y = false;
        bool z = false;

        for(int i =0;i<n;i++){
           int a = triplets[i][0];
           int b = triplets[i][1];
           int c = triplets[i][2];

           if(a>target[0] || b>target[1] || c>target[2]){
            continue;
           }
           if(a==target[0]) x= true;
           if(b==target[1]) y= true;
           if(c==target[2]) z= true;

        }
        return x && y && z;
        
    }
};
