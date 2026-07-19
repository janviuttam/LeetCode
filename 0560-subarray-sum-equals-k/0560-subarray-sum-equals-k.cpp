class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        int result=0;
        int preSum=0;

        mp.insert({0,1});
        
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];

            if(mp.find(preSum-k)!=mp.end()){
                result+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        return result;
    }
};