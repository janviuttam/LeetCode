class Solution {
public:
    int bs(int start,int end,vector<int>& arr,int target){
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr[mid] == target)
                return mid;
            else if(target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0, end = n - 1;
        int min_index = 0;

        while(start <= end){
            if(arr[start] <= arr[end]){
                min_index = start;
                break;
            }

            int mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                min_index = mid;
                break;
            }
            else if(arr[mid] >= arr[start]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        int fh = bs(0, min_index - 1, arr, target);
        int sh = bs(min_index, n - 1, arr, target);

        if(fh != -1) return fh;
        return sh;
    }
};