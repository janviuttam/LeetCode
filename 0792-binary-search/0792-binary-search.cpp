class Solution {
public:
    int bsearch(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<=target)
            {
                return bsearch(nums,mid+1,high,target);
            } 
            else 
            {
                return bsearch(nums,0,mid-1,target);
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
       int n=nums.size();
       int k=bsearch(nums,0,n-1,target);
       return k;
    
    }
};