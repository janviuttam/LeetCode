class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int i:nums){
            if(count==0){
                candidate=i;
            }
            if(i==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};