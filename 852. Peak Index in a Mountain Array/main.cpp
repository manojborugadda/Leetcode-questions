class Solution {//TC:logn SC:O(1)
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 1, high = n-2;
        while(low <= high) {
            int mid = (high+low)>>1;
            if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]) {
                return mid;
            }else if(arr[mid-1] < arr[mid]){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return 0;
    }
};
