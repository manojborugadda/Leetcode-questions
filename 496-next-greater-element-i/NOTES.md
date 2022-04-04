https://www.youtube.com/watch?v=V5r7PQhcJCQ
​
https://leetcode.com/problems/next-greater-element-i/discuss/1852333/C%2B%2B-solution-brute-force-greaterOptimall
​
vector nextGreaterElement(vector &nums1, vector &nums2)
{
​
unordered_map<int, int> mp;
stackst;
for (int i = nums2.size() - 1; i >= 0; i--)
{
while (!st.empty() && st.top() <= nums2[i])
st.pop();
if (st.empty())
mp[nums2[i]] = -1;
else
mp[nums2[i]] = st.top();
st.push(nums2[i]);
}
vectorv;
for (int i = 0; i < nums1.size(); i++)
{
v.push_back(mp[nums1[i]]);
}
return v;
}