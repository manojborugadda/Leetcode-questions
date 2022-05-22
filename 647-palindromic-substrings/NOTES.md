https://www.youtube.com/watch?v=fsW_PiMlyac
​
​
​
​
/*  Brute Force -> generating all the subsets - O(N^2) and checking palindrome or not for each - O(N)
Time Complexity  -> O(N^3)
Space Complexity -> O(1) */
class Solution {
public:
int countSubstrings(string s)
{
int n=s.size();
int cnt=0;
for(int i=0;i<n;i++)
{
string str="";
for(int j=i;j<n;j++)
{
str+=s[j];
if(isPalindrome(str))
cnt++;
}
}
return cnt;
}
bool isPalindrome(string str)
{
int left=0,right=str.size()-1;
while(left<right)
{
if(str[left++]!=str[right--])
return false;
}
return true;
}
};