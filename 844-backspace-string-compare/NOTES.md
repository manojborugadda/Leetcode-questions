https://leetcode.com/problems/backspace-string-compare/discuss/1996529/Well-Explained-C%2B%2B-Easiest-Solution-oror-SC%3A-O(1)-oror-Fast-and-simple
​
​
class Solution {
public:
bool backspaceCompare(string s, string t) {
int j=0,k=0;
// for 1st string
for(int i=0;i<s.size();i++)
{
if(s[i]=='#')
{
j--;
j=max(0,j); // j will never be -ve
}
else
{
s[j]=s[i];
j++;
}
}
// for 2nd string
for(int i=0;i<t.size();i++)
{
if(t[i]=='#')
{
k--;
k=max(0,k); // k will never be -ve
}
else
{
t[k]=t[i];
k++;
}
}
if(j!=k) return false;
else
{
for(int i=0;i<k;i++)
{
if(s[i]!=t[i]) return false;
}
return true;
}
}
};
​
​