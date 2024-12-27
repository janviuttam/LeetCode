/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i;
    int* ReturnSize = (int*)malloc(2 * sizeof(int));
    *returnSize=2;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                ReturnSize[0]=i;
                ReturnSize[1]=j;
                return ReturnSize;
            }
        }
    }
    // ReturnSize[0] = 0;
    // ReturnSize[1] = 1;
    return ReturnSize;
}