https://www.youtube.com/watch?v=4sQL7R5ySUU
​
///By iterating over nums array
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
vector<int>ans;
int first = -1, last = -1;
for(int i = 0; i < nums.size(); i++){
if(nums[i] == target){
if(first == -1){
first = i;
last = i;
}
else
last = i;
}
}
ans.push_back(first);
ans.push_back(last);
return ans;
}
};
​
//Using Unordered map
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
vector<int>ans(2, -1);
unordered_map<int,int>mp;
for(int i = 0; i < nums.size(); i++)
mp[nums[i]]++;
int index = -1;
for(int i = 0; i < nums.size(); i++)
if(nums[i] == target){
index = i;
break;
}
if(index != -1){
ans[0] = index;
ans[1] = index + mp[target] - 1;
}
return ans;
}
};
​
​
​
​