int count=0;
int ans=0;
for(int i=0;i<nums.size();i++){
if(nums[i]==1){
count++;
ans=max(count,ans);
// for first iteration count=ans
// if in second iteration nums[i]==0 than count =0 and ans remains as it is in first iteration. and keep on updating if count is greater than ans.
}
else{
count=0;
}
}
return ans;