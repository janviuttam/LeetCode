class Solution {
public:
    int maxProduct(int n) {
        int m1=-1, m2=-1;
        while(n>0){
            int i=n%10;
            if(i>=m1){
                m2=m1;
                m1=i;
            }
            else if(i>=m2){
                m2=i;
            }
            n=n/10;
        }
        return m1*m2;
    }
};