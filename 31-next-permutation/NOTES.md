https://www.youtube.com/watch?v=LuLCLgMElus
​
```
void nextPermutation(vector<int>& nums) {
// using two pointers approach
int n = nums.size(), k, l;
// starting from back if we found a larger element we will stop
for (k = n - 2; k >= 0; k--) {
if (nums[k] < nums[k + 1]) {
break;
}
}
// if no element was found we will reverse the array
if (k < 0) {
reverse(nums.begin(), nums.end());
}
// else we find another bigger number and swap them to get next permutation
else{
for (l = n - 1; l > k; l--) {
if (nums[l] > nums[k]) {
break;
}
}
swap(nums[k], nums[l]);
reverse(nums.begin() + k + 1, nums.end());
}
}
```