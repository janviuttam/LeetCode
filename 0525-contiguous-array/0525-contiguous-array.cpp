class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;

        int preSum=0;
        int maxLength=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                preSum+=-1;
            }
            else{
                preSum+=1;
            }
            if(mp.find(preSum)!=mp.end()){
                int length=i-mp[preSum];
                maxLength=max(maxLength,length);
            }
            else{
                mp[preSum]=i;
            }
        }
        return maxLength;
    }
};