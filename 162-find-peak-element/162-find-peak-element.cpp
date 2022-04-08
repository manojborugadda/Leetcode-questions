 /*
 
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();
    }
}; 

*/

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0 , high = arr.size()-1;
        while(low < high){
            
            int mid = (low+high)>>1; // mid = low+(high-low)/2;
            
            if(arr[mid]<arr[mid+1])
            {
                low = mid+1;
                
            }
            else
               high = mid;
        }
        
        return low;
    }
};