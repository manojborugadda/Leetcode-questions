https://www.youtube.com/watch?v=_0wLomqNVHU
​
​
int threeSumMulti(vector<int>& a, int t) {
​
int n=a.size();
unordered_map<int,long> mp;
int i,m=1e9+7;
long c=0;
​
for(i=0;i<n;i++)
mp[a[i]]++;
​
for(auto it1:mp)
{
if(it1.first>t)
continue;
​
for(auto it2:mp)
{
​
int x=it1.first;
int y=it2.first;
int z=t-x-y;
​
if(mp.find(z)!=mp.end())
{
if(x==y && y==z)
c+=mp[x]*(mp[x]-1)*(mp[x]-2)/6;
else if(x==y && y!=z)
c+=mp[x]*(mp[x]-1)/2*mp[z];
else if(x<y && y<z)
c+=mp[x]*mp[y]*mp[z];
​
c=c%m;
}
}
}
​
return c;
}