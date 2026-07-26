class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1=INT_MIN,m2=INT_MIN,m3=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX;

        for(int n:nums){
            if(n>=m1){
                m3=m2;
                m2=m1;
                m1=n;
            }
            else if(n>=m2){
                m3=m2;
                m2=n;
            }
            else if(n>=m3){
                m3=n;
            }

            if(n<=min1){
                min2=min1;
                min1=n;
            }
            else if(n<=min2){
                min2=n;
            }
        }
        return max(m1*m2*m3,min1*min2*m1);
    }
};