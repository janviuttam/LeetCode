/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let j=0;
    let n=nums.length;
    for(let i=0;i<n;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
    }
    while(j<n){
        nums[j]=0;
        j++;
    }
};