1. calculate each sum for x in nums1 and y in nums2 Store it in map with frequency
2. make loop to check for sum of p in nums3 and q in nums4 , check if (-(p+q)) is present in map
​
unordered_map<int,int> sum1;
for(int x : nums1){
for(int y : nums2){
sum1[x+y]++;
}
}
int cnt = 0;
for(int x : nums3){
for(int y : nums4){
if(sum1.count((-(x+y)))==1){
cnt+= sum1[(-(x+y))];
}
}
}
return cnt;