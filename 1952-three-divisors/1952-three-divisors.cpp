class Solution {
public:
    bool isPrime(int n){
        if(n<2){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool isThree(int n) {
        int s=sqrt(n);
        if(s*s!=n){
            return false;
        }
        return isPrime(s);
    }
};