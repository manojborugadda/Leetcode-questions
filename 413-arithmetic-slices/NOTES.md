//size is less than 3
int l=nums.size();
if(l<=2)
return 0;
//finding arithmetic subarray length
int count=0;
//to store all arithmetic subarray of length at least 3
int res=0;
for(int i=2;i<l;i++){
//check if current element makes arithmetic sequence with previous two elements
if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
++count;
}//begin with a new element for new arithmetic sequences
else{
count=0;
}
//accumulate result in till i.
res+=count;
}
//return final count
return res;
}