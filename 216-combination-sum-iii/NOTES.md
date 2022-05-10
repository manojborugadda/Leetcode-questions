https://leetcode.com/problems/combination-sum-iii/discuss/2024165/EasyororRuntime%3A-0-ms-faster-than-100.00ororeExplnation
​
class Solution {
public:
void solve(int s,int k,int n,vector<int> &v,vector<vector<int>> &ans)
{
if(k<=0)
{
if(n==0) ans.push_back(v);
return;
}
for(int i=s;i<=9;i++)
{
v.push_back(i);
solve(i+1,k-1,n-i,v,ans);
v.pop_back();
}
}
vector<vector<int>> combinationSum3(int k, int n)
{
vector<vector<int>> ans;
vector<int> v;
solve(1,k,n,v,ans);
return ans;
}
};