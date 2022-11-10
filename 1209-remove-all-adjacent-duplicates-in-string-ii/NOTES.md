https://www.youtube.com/watch?v=x8R-_PnNdTE
​
`https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/2014241/Very-Simple-oror-Easy-to-understand-oror-With-Comments-oror-C%2B%2B-oror-O(n)`
​
/// another approach using STACKS
​
class Solution {
public:
​
string removeDuplicates(string s, int k) {
stack<pair<char,int>> st;
for(int i=0;i<s.length();i++){
if(!st.empty() && st.top().first==s[i]){
++st.top().second;
if(st.top().second==k)
st.pop();
}
else
st.push({s[i],1});
}
string res="";
while(!st.empty()){
for(int i=1;i<=st.top().second;i++)
res+=st.top().first;
st.pop();
}
reverse(res.begin(),res.end());