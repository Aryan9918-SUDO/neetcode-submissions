class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int left =0;
        int right = n-1;
        int count =0;
        while(left<=right){
            int weight=people[left]+people[right];
            if(weight<limit||weight==limit){
                count++;
                left++;
                right--;
            }
            if(weight>limit){
                count++;
                right--;
            }
           
        }
        return count;
        
    }
};