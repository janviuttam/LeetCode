class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int start=0, end=arr.size()-1, mid;
        char res=arr[0];
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==x)
                start=mid+1;
            else if(arr[mid]>x){
                res=arr[mid];
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
};