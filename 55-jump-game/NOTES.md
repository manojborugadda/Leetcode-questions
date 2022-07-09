https://leetcode.com/problems/jump-game/discuss/1150021/C%2B%2B-Solutions-Greedy-or-Recursive-or-DP
​
https://leetcode.com/problems/jump-game/discuss/1300303/Efficient-logic-in-C%2B%2B
​
class Solution {
public:
bool canJump(vector<int>& nums) {
int n=nums.size();
if(n==0) return 0;
int maxreach=0;
for(int i=0; i<n; i++){
if(maxreach<i)
return false;
maxreach=max(maxreach, i + nums[i]);
}
return true;
}
};
​
​
​
class Solution {
public:
bool canJump(vector<int>& nums) {
int n=nums.size();
int reachable=0;
for(int i=0;i<n;i++){
if(i>reachable) return false;
reachable=max(reachable,i+nums[i]);
}
return true;
}
};