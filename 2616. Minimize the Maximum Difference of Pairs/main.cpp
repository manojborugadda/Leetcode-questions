class Solution { //O(nlogn) + O(log(d)*n) for searching --- effectively O(log(d)*n)
public:///SC:O(1)
    bool isPossible(int diff ,vector<int>& nums,int p ) {
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] - nums[i-1] <= diff) {
                p--;
                i += 1;
            }
        }
        return p <= 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int start = 0 , end = nums[n-1] - nums[0];
        while(start < end) {
            int mid = (start+end)>>1;
            if(isPossible(mid , nums, p)) {
                end = mid;
            }else {
                start = mid+1;
            }
        }
        return start;
    }
};



/*So when we do the binary search on answer in range [min diff, max_diff] of the sorted array, we send mid in is_possible(mid) function.
The function gives the number of pairs whose difference is less than or equal to mid. If its' possible to make atleast p pairs, we return true.
Now all the values greater than the mid, will obviously give true answer.
So we reduce the search space to low- mid.
This way the minimum of all mid is obtained.
In is_possible() function, if a pair gives diff less than mid, then jump to next pair ie., eliminate first two indices, i.e.,i+= 2, else just eliminate the i-th index only*/
