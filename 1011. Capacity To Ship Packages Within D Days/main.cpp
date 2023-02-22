class Solution {//TC:O(n logm),SC;O(1)
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()),
        end = accumulate(weights.begin(), weights.end(), 0);
        int minCap=0;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(weights, days, mid)){
                minCap = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return minCap;
    }

    bool check(vector<int>& weights, int days, int capacity){
        int requiredDays = 1;
        int currWeight = 0;
        for(int i : weights){
            if(currWeight + i > capacity){
                requiredDays++;
                currWeight = 0;
            }
            currWeight += i;
        }
        if(requiredDays > days) return false;
        return true;
    }
};
