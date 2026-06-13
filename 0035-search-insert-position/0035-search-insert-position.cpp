class Solution {
public:

    int bsearch(vector<int>& nums, int target, int low, int high)
    {
        if(low > high)
            return low;

        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;

        if(target < nums[mid])
            return bsearch(nums, target, low, mid - 1);

        return bsearch(nums, target, mid + 1, high);
    }

    int searchInsert(vector<int>& nums, int target) {

        return bsearch(nums, target, 0, nums.size()-1);
    }
};