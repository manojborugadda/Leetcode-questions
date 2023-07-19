class Solution { //TC:O(N)  SC:O(1) --- no extra space since we are using Moore's Voting algorithm
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        //finding the majority element using Moore's Voting Algorithm
        int majority = nums[0] , count = 1;
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] == majority) {
                count++;
            }else {
                count--;
            }
            if(count == 0) {
                majority = nums[i];
                count = 1;
            }
        }


        //getting the frequency of the majority element
        int majorityFreq = 0;
        for(int num : nums) {
            if(num == majority ) {
                majorityFreq++;
            }
        }

        //traversing the array for finding the index where valid splitting is happening
        int leftCount = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == majority) {
                leftCount++;
            }
            // check if it is majority in both halfs
            if( (leftCount*2 > i+1)  and ( ( majorityFreq - leftCount)*2 > n-i-1) ) {
                return i;
            }
        }
        return -1;
    }
};
