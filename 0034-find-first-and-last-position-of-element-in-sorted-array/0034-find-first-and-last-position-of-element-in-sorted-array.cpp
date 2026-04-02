class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        int low = 0, high = nums.size() - 1, mid;

        // find first occurrence
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else {
                if (nums[mid] == target)
                    answer[0] = mid;
                high = mid - 1;
            }
        }

        // find last occurrence
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] > target)
                high = mid - 1;
            else {
                if (nums[mid] == target)
                    answer[1] = mid;
                low = mid + 1;
            }
        }

        return answer;
    }
};