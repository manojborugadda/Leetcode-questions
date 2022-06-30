https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/2216088/Short-and-Simple-solution
​
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/2216211/Median-better-than-average!-Developing-intution
​
​
​
​
class Solution {
public:
int minMoves2(vector<int>& nums) {
int n = nums.size(), pivot, ans = 0;
sort(begin(nums), end(nums));
if(n % 2 == 0) // Even number
pivot = (nums[n / 2 - 1] + nums[n / 2])/2; // average of 2 middle elements
else           // Odd number
pivot = nums[n/2];
for(auto i: nums)
ans += abs(i - pivot); // take the absolute difference from the pivot number
return ans;
}
};
​
​
​
Because the median element will lie between the shortest range in the middle and taking the difference from the median will give the minimum possible value for this shortest range.
​