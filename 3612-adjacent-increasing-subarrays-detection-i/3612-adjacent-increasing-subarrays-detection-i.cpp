class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0, m = i, n = 0;
        while (i + 2 * k <= nums.size()){
            bool first = true, second = true;
            for (int a = i; a < i + k - 1; a++){
                if (nums[a] >= nums[a + 1]){ 
                    first = false; 
                    break; 
                }
            }
            for (int b = i + k; b < i + 2 * k - 1; b++){
                if (nums[b] >= nums[b + 1]){ 
                    second = false; 
                    break; 
                }
            }
            if (first && second) 
                return true;

            i++;
            m = i;
            n = 0;
        }
        return false;
    }
};