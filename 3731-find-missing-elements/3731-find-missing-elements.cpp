class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;

        int mn=INT_MAX;
        int mx=INT_MIN;

        for(int n:nums){
            mp[n]++;
            if(n<mn){
                mn=n;
            }
            if(n>mx){
                mx=n;
            }
        }

        for(int i=mn;i<=mx;i++){
            if(mp.find(i)!=mp.end()){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};