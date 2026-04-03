class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int start=0, end=n-1, prev, next, mid;
        while(start<=end){
            if (arr[start] <= arr[end])
                return arr[start];
                
            mid=start+(end-start)/2;
            prev=(mid+n-1)%n;
            next=(mid+1)%n;
            
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
                return arr[mid];
            }
            else if(arr[mid]>=arr[start]){
                start=mid+1;
            }
            else if(arr[mid]<=arr[end]){
                end=mid-1;
            }
        }
        return arr[mid];
    }
};