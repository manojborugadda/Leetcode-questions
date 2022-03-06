double findMaxAverage(vector<int>& nums, int k) {
double average = INT_MIN*1.0, sum = 0.0;
int left = 0, right = 0;
while(right < nums.size()){
sum = sum + nums[right];
int lengthOfSubarray = (right-left+1);
if(lengthOfSubarray == k){
average = max(average,(sum/k));
sum = sum - nums[left];
left++;
}
right++;
}
return average;
}