string s = to_string(x);
int left = 0;
int right = s.size()-1;
while(left <= right)
{
if(s[left] == s[right])
{
left++;
right--;
}
else
{
return false;
}
}
return true;