Using Sorting
​
int missingNumber(vector<int>& nums)
{
sort(nums.begin(),nums.end());
int n=nums.size();
for(int i=0;i<n;i++){
if(i!=nums[i]){
return i;
}
}
return n;
}
Using HashMap------------------------------------
​
int missingNumber(vector<int>& nums) {
unordered_map<int,int>mp;
int n=nums.size();
for(auto i:nums){
mp[i]++;
}
for(int i=0;i<=n;i++){
if(mp[i]==0){
return i;
}
}
return -1;
}