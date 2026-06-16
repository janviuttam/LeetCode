class Solution {
public:
    int climbStairs(int n){
        if(n==1||n==2){
            return n;
        }
        int a=1;
        int b=2;
        int curr;
        for(int i=3;i<=n;i++){
            curr=a+b;
            a=b;
            b=curr;
        }
        return curr;
    }
};