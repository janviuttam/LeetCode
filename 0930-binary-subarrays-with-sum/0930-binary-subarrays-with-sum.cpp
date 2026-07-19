class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int result=0;
        int preSum=0;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];

            if(mp.find(preSum-goal)!=mp.end()){
                result+=mp[preSum-goal];
            }
            mp[preSum]++;
        }
        return result;
    }
};