​
​
​
https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/1303871/C%2B%2B-oror-Iterative-and-BackTracking-oror-2-method-oror-100-Faster
​
// First Approach using Recursion and Backtracking---------------------
​
class Solution {
public:
vector<string>v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void generate(string digits,string temp,int start,vector<string> &ans)
{
if(temp.size()==digits.size())
{
ans.push_back(temp);
return;
}
for(auto i : v[digits[start]-'0'])
{
temp.push_back(i);
generate(digits,temp,start+1,ans);
temp.pop_back();
}
}
vector<string> letterCombinations(string digits) {
vector<string> ans;
if(digits.size()==0)
{
return ans;
}
string temp = "";
generate(digits,temp,0,ans);
return ans;
}
};
​
​
​
​
​
​
​
​
​
​
​
​
// Second Approach--------------
​
vector<string> ans;
map<int,string> m  { {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},                               {9,"wxyz"}
};
void dfs(string d,string current){
if(d.length()==0){