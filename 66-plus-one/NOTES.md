https://www.youtube.com/watch?v=mjesfcGW0CM
​
int i=digits.size()-1;
while(i>=0){
if(digits[i]!=9){
digits[i] += 1;
return digits;
}
digits[i] =0;
i--;
}
// if the number is [9,9,9] then the below case satisfies
//int arr[i+1] = 0;
vector<int>ans(i+1,0);
ans[0] = 1;
return ans;