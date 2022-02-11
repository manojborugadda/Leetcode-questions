https://www.youtube.com/watch?v=ufXxc8Vty9A
​
unordered_map<int,int> mpp;
​
mpp[0] = 1;
int sum = 0 , rem = 0 , count = 0;
for(int i = 0 ; i < nums.size() ; i++ ){
sum += nums[i];
int rem = sum%k;
if(rem < 0)
rem += k;
if(mpp.find(rem) == mpp.end())
mpp[rem] += 1;
else{
count += mpp[rem];
mpp[rem] += 1;
}
}
return count;