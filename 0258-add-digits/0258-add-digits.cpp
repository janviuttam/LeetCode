class Solution {
public:
    int addDigits(int num) {
        // int r=0;
        // int sum=0;
        // while(num>=10){
        //     while(num>0){
        //         r=num%10;
        //         sum+=r;
        //         num=num/10;
        //     }
        //     num=sum;
        // }
        if(num==0) return 0;
        return 1+(num-1)%9;
    }
};