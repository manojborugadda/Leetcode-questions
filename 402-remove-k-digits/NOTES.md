```
class Solution {
public:
string removeKdigits(string num, int k)
{
int n = num.size();
string ans ;
​
if(k == n)
return "0" ;
for(int i=0; i<n; i++)
{
while(!ans.empty() && ans.back() > num[i] && k > 0) {
ans.pop_back() ;
k-- ;
}
ans.push_back(num[i]) ;
}
while(k > 0 && !ans.empty()) {
ans.pop_back() ;
k-- ;
}
int i = 0;
while(ans[i] == '0') {                            // Remove all 0's from start of number if present
i++ ;
}
if(ans[0] == '0')
ans = ans.substr(i, n-i) ;
if(ans.empty())
return "0" ;
return ans ;
}
};
```
