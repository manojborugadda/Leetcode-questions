class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN*1.0;
        double sum = 0.0;
        int left =0,right = 0;
        while(right < nums.size() ){
            sum = sum+nums[right];
            int lengthSubarr = right-left+1;
            if(lengthSubarr == k){
                avg = max(avg,(sum/k));
                sum = sum-nums[left];
                left++;  //if slide window length == K the we update the window by subtracting the previous value
            }
            right++; // we add untill the window size equal to K;
        }
        return avg;
    }
};