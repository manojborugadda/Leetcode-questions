Simple we will check until square root of n. For every number two divisors will 1 and number itself so third can be its square root.
If you find this helpful please upvote.
​
class Solution
{
public:
bool isThree(int n) {
if(n==1 or n==2)
{
return false;
}
int a=sqrt(n);
if(a*a==n)
{
for(int i=2;i<a;i++)
{
if(n%i==0)
{
return false;
}
}
return true;
}
return false;
}
};