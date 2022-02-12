sort(nums.begin(),nums.end());
if(nums.size()<3) return 0;
int n = nums.size();
int m = nums[n-1]*nums[n-2]*nums[n-3];
int l = nums[n-1]*nums[1]*nums[0];
return max(m,l);