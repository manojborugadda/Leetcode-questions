if(n==0)
return {0};
vector<int> result(n+1);
result[0]=0;
for(int i=1; i<=n;i++)
{
int num = i,count = 0;
while(num > 0)
{
count += num % 2;       // if num%2==1 then we add into count, if 0 then doesn't affect on count
num = num / 2;
}
result[i] = count;
}
return result;