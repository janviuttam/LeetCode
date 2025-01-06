class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,index=0;
        for(i=0;i<nums.size();i++)
        {
            if(target<=nums[i])
                return index;
            index++;
        }
        return index;
    }
};