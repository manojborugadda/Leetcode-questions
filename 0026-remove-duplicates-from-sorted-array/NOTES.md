https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/1350762/C++-or-Brute-Force-or-Optimal(Two-Pointer-Method)-or-Solution-or-Time-O(N)-or-Auxiliary-Space-O(1)-or
​
```
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
// Optimal Solution
// Time O(N) & Auxiliary Space O(1) 
// Two Pointer Method
int len=nums.size();
if(len==0)
return 0;
int p1=0;
for(int p2=1;p2<len;p2++){
if(nums[p1]!=nums[p2]){
// If elements at p1 & p2 not equal, increment p1 and copy
// nums[p2] to nums[p1] so as to concentrate all unique
// elements in ascending order at the initial indices of the vector
p1++;
nums[p1]=nums[p2];
}
}
// p1 location is the final indice of the
// unique element subarray at the beginning of nums vector 
