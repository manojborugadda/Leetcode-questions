/////////////
​
vector<int> ans;
while( num) {
ans.push_back(num % 10);
num /= 10;
}
sort(ans.begin(), ans.end()); // 2 , 2, 3, 9
return  ans[0] * 10 + ans[2] + ans[1] * 10 + ans[3];