class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        int n=nums.size();
        long long max=0,s;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    s = (static_cast<long long>(nums[i]) - nums[j]) * nums[k];
                    if(s>max)
                    {
                        max=s;
                    }
                    
                }
            }

        }
        return max;  
    }
};