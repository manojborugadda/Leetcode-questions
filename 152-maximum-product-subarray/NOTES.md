https://leetcode.com/problems/maximum-product-subarray/discuss/1746278/C%2B%2B-Approach-Kadane-algorithm
​
int max_product=INT_MIN;
int curr_product = 1;
// we will check the max product from both side of array
//prefix sum max
for(int i=0; i<nums.size(); i++){
curr_product *= nums[i];
max_product = max(max_product, curr_product);
if(nums[i]==0)
curr_product=1;
}
curr_product = 1;
//[3 , -1 , 4]  this array can't give result if we just pass from front so we have to check from back also
//suffix sum max
for(int i = nums.size()-1 ; i>=0 ; i--)
{
curr_product *= nums[i];
max_product = max(max_product , curr_product);
if(nums[i]==0)
curr_product = 1;
}
return max_product;