class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;

        int result=0;
        int preSum=0,rem;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            if(preSum%k<0){
                rem=k+(preSum%k);
            }
            else{
                rem=preSum%k;
            }
            if(mp.find(rem)!=mp.end()){
                result+=mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};